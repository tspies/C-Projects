/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:45:51 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 10:00:24 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrstr(const char *s, char **arr, char c, size_t wd_count)
{
	size_t i;
	size_t wrd_len;
	size_t arr_index;

	i = 0;
	arr_index = 0;
	if (!arr)
		return (NULL);
	while (s[i] != '\0' && arr_index < wd_count)
	{
		wrd_len = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c)
		{
			i++;
			wrd_len++;
		}
		arr[arr_index] = ft_strsub(s, i - wrd_len, wrd_len);
		arr_index++;
	}
	arr[arr_index] = (NULL);
	return (arr);
}
