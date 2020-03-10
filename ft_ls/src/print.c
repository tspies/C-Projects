/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:59:07 by tspies            #+#    #+#             */
/*   Updated: 2020/03/10 13:21:24 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list  *print_list(t_list *ls)
{
    t_list *tmp;

    tmp = ls;
    while (ls)
    {
        ft_printf("   %s\n", ls->file->name);
        ls = ls->next;
    }
    ls = tmp;
    return (ls);
}

void	print_args(char **arg_list){
	int i = 0;
	while (arg_list[i]){
		ft_printf("Current Arg --> %s\n", arg_list[i]);
		i++;
	}
}