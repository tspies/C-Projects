/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 09:59:31 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 15:15:20 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	char	minint[12];

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			return (ft_strdup(ft_strcpy(minint, "-2147483648")));
		}
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10)
	{
		str[0] = (char)n + '0';
		str[1] = '\0';
	}
	return (str);
}
