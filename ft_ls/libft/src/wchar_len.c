/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <tspies@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:20:06 by tspies            #+#    #+#             */
/*   Updated: 2018/09/03 11:20:33 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		wchar_len(unsigned int nbr)
{
	if (nbr <= 127)
		return (1);
	else if (nbr >= 128 && nbr <= 2047)
		return (2);
	else if (nbr >= 2048 && nbr <= 65535)
		return (3);
	else if (nbr >= 65536 && nbr <= 2097151)
		return (4);
	else
		return (0);
}
