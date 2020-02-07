/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:23:38 by tspies            #+#    #+#             */
/*   Updated: 2018/08/21 09:23:39 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	unsigned_size(uintmax_t num, uintmax_t base)
{
	int		res;

	res = 1;
	num /= base;
	while (num)
	{
		num /= base;
		res++;
	}
	return (res);
}

int			unsigned_len(t_print *tab, uintmax_t num, uintmax_t base)
{
	int		res;
	int		tmp;

	res = unsigned_size(num, base);
	tmp = 0;
	if (tab->precision != -1 && tab->precision > res)
	{
		tmp = (tab->precision - res);
		res = tab->precision;
	}
	if (tmp > 0)
		tab->precision = tmp;
	else if (num == 0 && tab->precision == 0)
	{
		tab->precision = -2;
		res = 0;
	}
	else
		tab->precision = -1;
	return (res);
}
