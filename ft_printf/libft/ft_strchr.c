/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:56:20 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 14:43:24 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_strchr(char *s, int c)
{
	char	*tmp;

	tmp = s;
	while (*tmp != '\0')
	{
		if (*tmp == c)
			return (1);
		tmp++;
	}
	if (*tmp == '\0' && c == '\0')
		return (0);
	return (0);
}
