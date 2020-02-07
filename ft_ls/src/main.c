/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 02:41:49 by tristyn           #+#    #+#             */
/*   Updated: 2020/01/27 14:30:32 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_flag	*flags;
	int		nbr_arg;
	char	**arg_list;

	flags = ft_initialize_ls(ac, av);
	nbr_arg = arg_nbr_check(ac, av);
	ft_printf("Arguments: %d\n", nbr_arg);
	arg_list = parse_args(nbr_arg, flags, av);
	// print_args(arg_list);
	read_dir_stream(arg_list, flags);
	return (0);
}

