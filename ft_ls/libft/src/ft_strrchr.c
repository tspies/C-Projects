/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:52:34 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 14:44:15 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*bin;
	size_t	len;

	count = 0;
	bin = (char *)s;
	len = ft_strlen(bin);
	if (bin)
	{
		while (count < (int)len)
		{
			count++;
			bin++;
		}
		while (count >= 0)
		{
			if (*bin == (char)c)
				return (bin);
			bin--;
			count--;
		}
	}
	return (NULL);
}
