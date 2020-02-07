/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:17:13 by tspies            #+#    #+#             */
/*   Updated: 2018/08/16 15:01:29 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, fmt);
	while (*fmt != '\0')
	{

		if (*fmt != '%')
			len += ft_putchar(*fmt);
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
