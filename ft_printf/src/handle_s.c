/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:37:02 by tspies            #+#    #+#             */
/*   Updated: 2018/08/17 14:37:03 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		check_null(void *str)
{
	if (str != NULL)
		return (ft_strlen((char *)str));
	return (6);
}

int		precision_check(t_print *tab)
{
	if (!tab->precision)
		return (tab->f_width);
	return (tab->size);
}

int		handle_s(t_print *tab, void *str)
{
	int		res;

	res = 0;
	tab->size = (str != NULL) ? ft_strlen((char *)str) : 6;
	tab->size = !tab->precision ? tab->f_width : tab->size;
	if (tab->flag_list[2] == '0')
		tab->flag_list[0] = '0';
	while (tab->f_width > tab->size && (tab->flag_list)[3] != '-')
		(res += ft_putchar((tab->flag_list)[0])) && tab->f_width--;
	while (tab->f_width > tab->precision && (tab->flag_list)[3] != '-' &&
	tab->precision != -1 && (tab->size > tab->precision))
		(res += ft_putchar((tab->flag_list)[0])) && tab->f_width--;
	if (tab->specifier == 's' && !tab->l)
		res += ft_putstr((char *)str, tab->precision);
	else if ((tab->l && tab->specifier == 's') || tab->specifier == 'S')
		res += ft_put_wstr((wchar_t *)str, tab->precision);
	while (tab->f_width > tab->size && (tab->flag_list)[3] == '-')
		(res += ft_putchar(' ')) && tab->f_width--;
	while (tab->f_width > tab->precision && (tab->flag_list)[3] == '-' &&
	tab->precision != -1 && (tab->f_width-- - tab->precision))
		res += ft_putchar(' ');
	return (res);
}
