/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <tspies@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:19:42 by tspies            #+#    #+#             */
/*   Updated: 2018/09/03 11:19:52 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_wstr(wchar_t *wstr, int prec)
{
	int		res;

	res = 0;
	if (wstr == NULL)
		return (ft_print_str("(null)", prec));
	while (*wstr != '\0')
	{
		res += ft_put_wchar(*wstr);
		wstr++;
	}
	return (res);
}
