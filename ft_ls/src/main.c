/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 02:41:49 by tristyn           #+#    #+#             */
/*   Updated: 2020/06/16 22:01:15 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int first = 0;

int		main(int ac, char **av)
{
	t_flag	*flags = NULL;
	int		nbr_arg = 0;
	int		i = 0;
	char	**arg_list = (char **)malloc(sizeof(char *) * (999 + 1));
	// arg_list = (char **)malloc(sizeof(char ) * (999 + 1));
	flags = (t_flag *)malloc(sizeof(t_flag) * 1);
	// set_all_to_null(arg_list);
	ft_initialize_ls(av, flags);
	nbr_arg = arg_nbr_check(ac, av);
	// ft_printf("Arguments: %d\n", nbr_arg);
	parse_args(nbr_arg, flags, av, arg_list);
	// ft_printf("Arg NUMBER: %d\n", nbr_arg);
	// if (arg_list)
		// print_args(arg_list);
	if (flags->flag_r == 1){
		while(arg_list[i]){
			read_dir_stream(arg_list[i], flags);
			// if (flags->flag_multi == 1 && nbr_arg == 3 && i == 0 && flags->flag_R == 0)
			// 	ft_putchar('\n');
			// else if (flags->flag_multi == 1 && nbr_arg == 2 && i == 0 && flags->flag_R == 0)
			// 	ft_putchar('\n');
			// else if (flags->flag_multi == 1 && nbr_arg > 3 && (i < nbr_arg - 2) && flags->flag_R == 0)
			// 	ft_putchar('\n');
			i++;
		}
	}
	else{
		if (flags->flag_err == 0 && nbr_arg > 2)
			i = nbr_arg - 2;
		else if (flags->flag_err == 0 && nbr_arg == 1)
			i = 0;
		else if (flags->flag_err == 1 && nbr_arg > 1)
			i = nbr_arg - 1;
		else
			i = 0;	
		while(i > -1){
			read_dir_stream(arg_list[i], flags);
			// if (flags->flag_multi == 1 && nbr_arg == 3 && i == 0 && flags->flag_R == 0)
			// 	ft_putchar('\n');
			// else if (flags->flag_multi == 1 && nbr_arg == 2 && i == 0 && flags->flag_R == 0)
			// 	ft_putchar('\n');
			// else if (flags->flag_multi == 1 && nbr_arg > 3 && (i < nbr_arg - 2) && flags->flag_R == 0)
			// 	ft_putchar('\n');
			i--;
		}
	}
	// ft_printf("%d\n", i);
	// ft_printf("%s \n\n", arg_list[i])
	
	free(arg_list);
	free(flags);
	return (0);
}

void set_all_to_null(char **arg_list){
	int x = 0;
	int y = 0;

	while(arg_list[x]){
		while(arg_list[y]){
			arg_list[y] = NULL;
			y++;	
		}
		x++;
	}
}