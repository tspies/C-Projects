/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:20:13 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 15:18:49 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *s, int precision)
{
	int		res;

	res = 0;
	if (s == NULL)
		return (ft_putstr("(null)", precision));
	while (*s && precision--)
	{
		res += ft_putchar(*s);
		s++;
	}
	return (res);
}
