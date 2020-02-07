/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:25:38 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 14:53:30 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s1;
	size_t	s2;
	size_t	i;

	i = 0;
	s1 = ft_strlen(dst);
	s2 = ft_strlen(src);
	if (dstsize == 0)
		return (s1);
	if (dstsize - 1 <= s1)
		return (s2 + dstsize);
	while ((dstsize - 1 > s1 + i) && src[i])
	{
		dst[s1 + i] = src[i];
		i++;
	}
	dst[s1 + i] = '\0';
	return (s1 + s2);
}
