/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:22:02 by tspies            #+#    #+#             */
/*   Updated: 2018/08/16 17:33:40 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	int		i;

	i = 42;
	ft_printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	//printf("%s %C %d %p %x %% %S", "Bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	return (0);
}
