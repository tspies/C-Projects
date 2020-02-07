/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:46:14 by tspies            #+#    #+#             */
/*   Updated: 2018/08/21 15:46:16 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		special_case(t_print *tab, uintmax_t num)
{
	if ((tab->flag_list)[1] == '#' && (tab->flag_list)[0] == ' ' && num != 0)
		tab->size += 2;
}

static int		check_x(t_print *tab)
{
	int		res;

	res = 0;
	if (tab->specifier == 'x')
	{
		res += ft_putstr("0x", -1);
		tab->size += 2;
	}
	else
	{
		res += ft_putstr("0X", -1);
		tab->size += 2;
	}
	return (res);
}

static int		print_x(t_print *tab, uintmax_t num, uintmax_t base,
				char *base_list)
{
	int		res;

	res = 0;
	if (num == 0 && tab->precision == -2)
		return (0);
	if (num >= base)
	{
		res += print_x(tab, num / base, base, base_list);
		res += ft_putchar(base_list[num % base]);
	}
	else
		res += ft_putchar(base_list[num % base]);
	return (res);
}

static int		flags_for_x(t_print *tab, uintmax_t num, uintmax_t base)
{
	int		res;

	res = 0;
	zero_check(tab);
	tab->size = unsigned_len(tab, num, base);
	special_case(tab, num);
	if ((tab->flag_list)[1] == '#' && (tab->flag_list)[0 == '0'] &&
		(tab->flag_list)[3] == '-' && num != 0)
		res += check_x(tab);
	if (tab->flag_list[0] == '0' && tab->flag_list[1] == '#' &&
		num != 0 && tab->flag_list[3] != '-')
		res += check_x(tab);
	while (tab->flag_list[3] != '-' && tab->f_width > (tab->size))
		(res += ft_putchar(tab->flag_list[0])) && tab->f_width--;
	if ((tab->flag_list)[1] == '#' && (tab->flag_list)[0] == ' ' && num != 0)
		res += check_x(tab);
	while (tab->precision != -1 && tab->precision > 0)
		(res += ft_putchar('0')) && tab->precision--;
	if (tab->specifier == 'x')
		res += print_x(tab, num, base, "0123456789abcdef");
	if (tab->specifier == 'X')
		res += print_x(tab, num, base, "0123456789ABCDEF");
	while ((tab->flag_list)[3] == '-' && tab->f_width > tab->size)
		(res += ft_putchar(' ')) && tab->f_width--;
	return (res);
}

int				handle_x(t_print *tab, void *num, uintmax_t base)
{
	if (tab->l)
		return (flags_for_x(tab, (unsigned long)num, base));
	else if (tab->ll)
		return (flags_for_x(tab, (unsigned long)num, base));
	else if (tab->h)
		return (flags_for_x(tab, (unsigned short)num, base));
	else if (tab->hh)
		return (flags_for_x(tab, (unsigned char)num, base));
	else if (tab->j)
		return (flags_for_x(tab, (uintmax_t)num, base));
	else if (tab->z)
		return (flags_for_x(tab, (size_t)num, base));
	else
		return (flags_for_x(tab, (unsigned int)num, base));
}
