/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_switchboard.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:09:12 by tspies            #+#    #+#             */
/*   Updated: 2018/08/16 15:11:56 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		specifier_switchboard(t_print *tab, va_list arg)
{
	int		res;

	if (tab->specifier == 's' || tab->specifier == 'S')
		res = (handle_s(tab, va_arg(arg, void *)));
	else if (tab->specifier == 'c' || tab->specifier == 'C')
		res = (handle_c(tab, va_arg(arg, void *)));
	else if (tab->specifier == 'd' || tab->specifier == 'D' ||
	tab->specifier == 'i')
		res = (handle_d(tab, va_arg(arg, void *), 10));
	else if (tab->specifier == 'u' || tab->specifier == 'U')
		res = (handle_u(tab, va_arg(arg, void *), 10));
	else if (tab->specifier == 'o' || tab->specifier == 'O')
		res = (handle_o(tab, va_arg(arg, void *), 8));
	else if (tab->specifier == 'x' || tab->specifier == 'X')
		res = (handle_x(tab, va_arg(arg, void *), 16));
	else if (tab->specifier == 'p')
		res = (handle_p(tab, va_arg(arg, void *), 16));
	else if (tab->specifier == '%')
		res = (ft_put_percent(tab, '%'));
	else
		res = (handle_c(tab, va_arg(arg, void *)));
	ft_strdel(&(tab->flag_list));
	return (res);
}
