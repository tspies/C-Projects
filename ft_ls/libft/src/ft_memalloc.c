/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:08:40 by tspies            #+#    #+#             */
/*   Updated: 2020/06/15 00:20:24 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;
	int		i;

	i = (int)size;
	if (i <= 0)
		return (NULL);
	if (!(area = (void*)malloc(sizeof(*area) * i)))
		return (NULL);
	ft_bzero(area, i);
	return (area);
}
