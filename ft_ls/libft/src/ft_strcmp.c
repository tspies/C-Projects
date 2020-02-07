/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <tspies@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:16:02 by tspies            #+#    #+#             */
/*   Updated: 2018/09/28 14:44:37 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	char	*string1;
	char	*string2;

	string1 = (char *)s1;
	string2 = (char *)s2;
	while ((*string1 == *string2) && *string1 != '\0' && *string2 != '\0')
	{
		string1++;
		string2++;
	}
	return ((int)(*(unsigned char *)string1 - *(unsigned char *)string2));
}
