/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <tspies@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:19:30 by tspies            #+#    #+#             */
/*   Updated: 2018/09/03 11:19:36 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		ft_put_wchar(wchar_t wchar)
{
	char			res;
	char			size;
	unsigned char	byte_index;

	res = 0;
	size = wchar_len(wchar);
	if (size == 1)
		return (ft_print_char(wchar));
	byte_index = (240 << (4 - size)) | (wchar >> ((size - 1) * 6));
	res += ft_print_char(byte_index);
	size--;
	while (size--)
	{
		byte_index = ((wchar >> ((size) * 6)) & 63) | 128;
		res += ft_print_char(byte_index);
	}
	return (res);
}
