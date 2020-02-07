/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:45:26 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 15:14:06 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*end;
	char	*start;

	if (!s)
		return (NULL);
	start = (char *)s;
	end = (ft_strrchr(s, 0) - 1);
	while (ft_isspace(*start))
		start++;
	while (ft_isspace(*end) && end > start)
		end--;
	return (ft_strsub((const char *)start, 0, (end - start) + 1));
}
