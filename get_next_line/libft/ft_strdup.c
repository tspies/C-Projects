/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:55:50 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 14:51:10 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*string;

	i = 0;
	string = (char *)malloc(ft_strlen(s1) + 1);
	if (string == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (string[i] != '\0')
	{
		string[i] = '\0';
		i++;
	}
	return (string);
}
