/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:06:20 by tspies            #+#    #+#             */
/*   Updated: 2018/06/05 13:44:43 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*end;
	char	c;

	end = str + ft_strlen(str) - 1;
	while (str < end)
	{
		c = *str;
		*str++ = *end;
		*end-- = c;
	}
	return (str);
}
