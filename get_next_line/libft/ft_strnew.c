/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:37:39 by tspies            #+#    #+#             */
/*   Updated: 2018/06/20 15:11:54 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
