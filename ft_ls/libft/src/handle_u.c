/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:40:16 by tspies            #+#    #+#             */
/*   Updated: 2018/08/16 16:40:17 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		print_unsigned(uintmax_t num, t_print *tab)
{
	char	res;

	res = 0;
	if (num == 0 && tab->precision == -2)
		return (0);
	if (num >= 10)
	{
		res += print_unsigned(num / 10, tab);
		res += ft_print_char((num % 10) + '0');
	}
	else
		res += ft_print_char(num + '0');
	return (res);
}

static int		flags_for_u(t_print *tab, uintmax_t num, uintmax_t base)
{
	int		res;

	res = 0;
	zero_check(tab);
	tab->size = unsigned_len(tab, num, base);
	while (tab->flag_list[3] != '-' && tab->f_width > (tab->size))
		(res += ft_print_char(tab->flag_list[0])) && tab->f_width--;
	while (tab->precision != -1 && tab->precision > 0)
		(res += ft_print_char('0')) && tab->precision--;
	res += print_unsigned(num, tab);
	while (tab->f_width > tab->size && (tab->flag_list)[3] == '-')
		(res += ft_print_char(' ')) && tab->f_width--;
	return (res);
}

int				handle_u(t_print *tab, void *num, uintmax_t base)
{
	if (tab->specifier == 'U')
		return (flags_for_u(tab, (unsigned long)num, base));
	else if (tab->l)
		return (flags_for_u(tab, (unsigned long)num, base));
	else if (tab->ll)
		return (flags_for_u(tab, (unsigned long long)num, base));
	else if (tab->h)
		return (flags_for_u(tab, (unsigned short)num, base));
	else if (tab->hh)
		return (flags_for_u(tab, (unsigned char)num, base));
	else if (tab->z)
		return (flags_for_u(tab, (size_t)num, base));
	else if (tab->j)
		return (flags_for_u(tab, (uintmax_t)num, base));
	else
		return (flags_for_u(tab, (unsigned int)num, base));
}
