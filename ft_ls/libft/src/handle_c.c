/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:03:56 by tspies            #+#    #+#             */
/*   Updated: 2018/08/16 15:06:22 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		handle_c(t_print *tab, void *c)
{
	int		res_len;

	res_len = 0;
	if ((tab->flag_list)[2] == '0')
		(tab->flag_list)[0] = '0';
	if ((tab->flag_list)[3] != '-' && tab->f_width > 1)
		while ((tab->f_width)-- - 1)
			res_len += ft_print_char(tab->flag_list[0]);
	if (tab->specifier == 'c' && !tab->l)
		res_len += ft_print_char((int)c);
	else if (tab->specifier == 'C' || (tab->specifier == 'c' && tab->l))
		res_len += ft_put_wchar((int)c);
	else
		res_len += ft_print_char(tab->specifier);
	if ((tab->flag_list)[3] == '-' && tab->f_width > 1)
		while ((tab->f_width)-- - 1)
			res_len += ft_print_char(' ');
	return (res_len);
}
