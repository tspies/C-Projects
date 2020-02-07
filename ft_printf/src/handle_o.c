/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 08:23:42 by tspies            #+#    #+#             */
/*   Updated: 2018/08/19 08:23:45 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		print_oct(uintmax_t oct, t_print *tab, char *oct_base)
{
	char	res;

	res = 0;
	if (oct == 0 && tab->precision == -2)
		return (0);
	if (oct >= 8)
	{
		res += print_oct(oct / 8, tab, oct_base);
		res += ft_putchar(oct_base[oct % 8]);
	}
	else
		res += ft_putchar(oct_base[oct % 8]);
	return (res);
}

static short	flags_for_oct(t_print *tab, uintmax_t oct, uintmax_t base)
{
	short	res;

	res = 0;
	zero_check(tab);
	tab->size = unsigned_len(tab, oct, base);
	if ((tab->flag_list)[1] == '#' && oct != 0)
		tab->size++;
	while (tab->f_width > tab->size && (tab->flag_list)[3] != '-')
		(res += ft_putchar((tab->flag_list)[0])) && tab->f_width--;
	if ((tab->flag_list)[1] == '#' && oct != 0)
		res += ft_putchar('0');
	else if ((tab->flag_list)[1] == '#' && oct == 0)
		res += ft_putchar('0');
	while ((tab->precision != -1) && (tab->precision > 0))
		(res += ft_putchar('0')) && tab->precision--;
	res += print_oct(oct, tab, OCT_LIST);
	while (tab->f_width > tab->size && (tab->flag_list)[3] == '-')
		(res += ft_putchar(' ')) && tab->f_width--;
	return (res);
}

int				handle_o(t_print *tab, void *oct, uintmax_t base)
{
	if (tab->specifier == 'O')
		return (flags_for_oct(tab, (unsigned long)oct, base));
	else if (tab->l)
		return ((flags_for_oct(tab, (unsigned long)oct, base)));
	else if (tab->ll)
		return (flags_for_oct(tab, (unsigned long long)oct, base));
	else if (tab->h)
		return ((flags_for_oct(tab, (unsigned short)oct, base)));
	else if (tab->hh)
		return ((flags_for_oct(tab, (unsigned char)oct, base)));
	else if (tab->z)
		return (((flags_for_oct(tab, (size_t)oct, base))));
	else if (tab->j)
		return (((flags_for_oct(tab, (uintmax_t)oct, base))));
	else
		return ((flags_for_oct(tab, (unsigned int)oct, base)));
}
