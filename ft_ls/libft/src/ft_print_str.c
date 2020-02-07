/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <tspies@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:18:42 by tspies            #+#    #+#             */
/*   Updated: 2018/09/03 11:18:58 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_str(char *s, int precision)
{
	int		res;

	res = 0;
	if (s == NULL)
		return (ft_print_str("(null)", precision));
	while (*s && precision--)
	{
		res += ft_print_char(*s);
		s++;
	}
	return (res);
}
