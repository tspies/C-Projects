/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:43:00 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 15:15:00 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	wd_count;
	char	**arr;

	if (!s)
		return (NULL);
	wd_count = ft_wdcount(s, c);
	arr = (char **)malloc(sizeof(char *) * (wd_count + 1));
	ft_arrstr(s, arr, c, wd_count);
	if (!arr)
		return (NULL);
	return (arr);
}
