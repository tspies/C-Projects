/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <tspies@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:17:13 by tspies            #+#    #+#             */
/*   Updated: 2018/09/03 11:25:02 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_printf(char *fmt, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			len += ft_print_char(*fmt);
		else
		{
			fmt++;
			len += parse_switchboard(&(fmt), arg);
		}
		fmt++;
	}
	va_end(arg);
	return (len);
}
