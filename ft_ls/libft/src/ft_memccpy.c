/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:21:58 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 14:36:09 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
		{
			s1[i] = s2[i];
			i++;
			return ((void *)&dst[i]);
		}
		s1[i] = s2[i];
		i++;
	}
	return (NULL);
}
