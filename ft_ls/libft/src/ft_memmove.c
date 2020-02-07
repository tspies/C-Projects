/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 09:18:01 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 14:39:14 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*char_dest;
	char		*char_src;
	size_t		i;

	char_dest = (char *)dst;
	char_src = (char *)src;
	i = 0;
	if (char_src < char_dest)
	{
		while (len--)
			char_dest[len] = char_src[len];
	}
	else
		ft_memcpy(char_dest, char_src, len);
	return (dst);
}
