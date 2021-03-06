/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:55:39 by tspies            #+#    #+#             */
/*   Updated: 2020/06/11 19:56:01 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char *ptr;

	ptr = dst;
	while (*src)
		*(ptr++) = *(src++);
	*ptr = *src;
	return (dst);
}
