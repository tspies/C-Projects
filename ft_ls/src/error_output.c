/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:33:36 by tspies            #+#    #+#             */
/*   Updated: 2020/01/24 21:53:01 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    straight_exit(void)
{
    exit(1);
}

void    flag_err_msg(char c)
{
    ft_printf("%s: illegal option -- %c\nusage: %s", NAME, c, NAME);
    ft_printf(" [-lRart] [file ...]\n");
    exit (1);
}

void	broken(void){
	ft_printf("Sorry! It seems something has broken\n\n");
	exit(1);
}