/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <tspies@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:18:03 by tspies            #+#    #+#             */
/*   Updated: 2018/09/03 11:18:58 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fatoi(char **str)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (((*str)[i] >= '0' && (*str)[i] <= '9'))
	{
		result = (result * 10) + ((*str)[i] - '0');
		i++;
	}
	(*str) = &(*str)[i];
	return (result * sign);
}
