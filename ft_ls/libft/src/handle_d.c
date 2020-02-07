/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:41:12 by tspies            #+#    #+#             */
/*   Updated: 2018/08/16 15:26:00 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		special_case(t_print *tab, intmax_t num)
{
	int		res;

	res = 0;
	if (num < 0 && (tab->flag_list)[0] == '0')
		res += ft_print_char('-');
	if (num < 0)
		tab->size++;
	if (num >= 0 && tab->flag_list[0] != '0' && tab->flag_list[5] == ' ')
		tab->size++;
	if (tab->flag_list[4] == '+' && num >= 0 && tab->flag_list[0] != '0')
		tab->size++;
	return (res);
}

static char		print_num(intmax_t num, t_print *tab)
{
	char	res;

	res = 0;
	if (num == 0 && tab->precision == -2)
		return (0);
	if (num > -10 && num < 10)
		res += ft_print_char(ABS(num) + '0');
	else
	{
		res += print_num(num / 10, tab);
		res += print_num(num % 10, tab);
	}
	return (res);
}

static short	flags_for_d(t_print *tab, intmax_t num, intmax_t base)
{
	int		res;

	res = 0;
	zero_check(tab);
	tab->size = signed_len(tab, num, base);
	res += special_case(tab, num);
	if (num >= 0 && tab->flag_list[4] == '+' && tab->flag_list[0] == '0')
		(res += ft_print_char('+')) && tab->size++;
	else if (tab->flag_list[0] == '0' && tab->flag_list[5] == ' ')
		res += ft_print_char(' ');
	while (tab->flag_list[3] != '-' && tab->f_width > (tab->size))
		res += (ft_print_char(tab->flag_list[0])) && tab->f_width--;
	if (tab->flag_list[4] == '+' && num >= 0 && tab->flag_list[0] != '0')
		res += ft_print_char('+');
	else if (num >= 0 && tab->flag_list[0] != '0' && tab->flag_list[5] == ' ')
		res += ft_print_char(' ');
	else if (num < 0 && tab->flag_list[0] == ' ')
		res += ft_print_char('-');
	while (tab->precision != -1 && tab->precision > 0)
		(res += ft_print_char('0')) && tab->precision--;
	res += print_num(num, tab);
	while (tab->f_width > tab->size && (tab->flag_list)[3] == '-')
		(res += ft_print_char(' ')) && tab->f_width--;
	return (res);
}

int				handle_d(t_print *tab, void *num, intmax_t base)
{
	if (tab->specifier == 'D')
		return ((flags_for_d(tab, (long)num, base)));
	else if (tab->l)
		return ((flags_for_d(tab, (long)num, base)));
	else if (tab->ll)
		return ((flags_for_d(tab, (long long)num, base)));
	else if (tab->h)
		return ((flags_for_d(tab, (short)num, base)));
	else if (tab->hh)
		return ((flags_for_d(tab, (char)num, base)));
	else if (tab->z)
		return ((flags_for_d(tab, (size_t)num, base)));
	else if (tab->j)
		return ((flags_for_d(tab, (intmax_t)num, base)));
	else
		return ((flags_for_d(tab, (int)num, base)));
}
