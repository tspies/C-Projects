/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:08:40 by tspies            #+#    #+#             */
/*   Updated: 2018/06/06 15:03:38 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_fresh;

	mem_fresh = malloc(size);
	if (mem_fresh == '\0')
		return (NULL);
	ft_bzero(mem_fresh, size);
	return (mem_fresh);
}
