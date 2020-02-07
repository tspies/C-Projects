/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <tspies@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:18:53 by tspies            #+#    #+#             */
/*   Updated: 2018/09/03 11:19:17 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_percent(t_print *tab, char c)
{
	int		res;

	res = 0;
	zero_check(tab);
	if ((tab->flag_list)[3] != '-' && tab->f_width > 1)
		while ((tab->f_width)-- - 1)
			res += ft_print_char((tab->flag_list)[0]);
	res += ft_print_char(c);
	if ((tab->flag_list)[3] == '-' && tab->f_width > 1)
		while ((tab->f_width)-- - 1)
			res += ft_print_char(' ');
	return (res);
}
