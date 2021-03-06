/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <tspies@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:24:26 by tspies            #+#    #+#             */
/*   Updated: 2018/09/03 11:24:38 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	put_p(uintmax_t ptr, t_print *tab, uintmax_t divd, char *base)
{
	int		res;

	res = 0;
	if (ptr == 0 && tab->precision == -2)
		return (0);
	if (ptr >= divd)
	{
		res += put_p(ptr / divd, tab, divd, base);
		res += ft_print_char(base[ptr % divd]);
	}
	else
		res += ft_print_char(base[ptr % divd]);
	return (res);
}

static int	flags_for_p(t_print *tab, uintmax_t ptr, intmax_t base)
{
	int		res;

	res = 0;
	zero_check(tab);
	tab->size = ptr_len(tab, ptr, base);
	if ((tab->flag_list)[0] == '0')
		res += ft_print_str("0x", -1);
	while ((tab->flag_list)[3] != '-' && tab->f_width > (tab->size))
		(res += ft_print_char((tab->flag_list)[0])) && tab->f_width--;
	if ((tab->flag_list)[0] == ' ')
		res += ft_print_str("0x", -1);
	while (tab->precision != -1 && tab->precision > 0)
		(res += ft_print_char('0')) && tab->precision--;
	res += put_p(ptr, tab, base, "0123456789abcdef");
	while ((tab->flag_list)[3] == '-' && tab->f_width > (tab->size))
		(res += ft_print_char(' ')) && tab->f_width--;
	return (res);
}

int			handle_p(t_print *tab, void *ptr, intmax_t base)
{
	return (flags_for_p(tab, (uintmax_t)ptr, base));
}
