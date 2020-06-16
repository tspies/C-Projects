/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 22:01:39 by tristyn           #+#    #+#             */
/*   Updated: 2020/06/16 21:32:37 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		arg_nbr_check(int ac, char **av){
	int		arg_nbr = 0;

	if (ac == 1)
		return arg_nbr;
	else if ((ac == 2 && !(ft_strncmp(av[1], "-", 1))) || (ac == 2 && (ft_strncmp(av[1], "-", 1))))
		return ++arg_nbr;
	else if (!(ft_strncmp(av[1], "-", 1) && av[2] != NULL)){
		++arg_nbr;
		while (av[arg_nbr + 1])
			++arg_nbr;
	}
	else if ((ft_strncmp(av[1], "-", 1)) && av[2] != NULL){
		while (av[arg_nbr + 1])
			++arg_nbr;
	}
	return arg_nbr;
}

void	parse_args(int nbr, t_flag *flags, char **av, char **arg_list){
	
	int 	i = 0;

	// ft_printf("FLAG Error = %d\n", flags->flag_err);
	if ((flags->flag_err == 0 && nbr >= 3) || (flags->flag_err == 1 && nbr >= 2)){
		flags->flag_multi = 1;
		// ft_printf("\n\nFlag Multi ON == %d\n\n", flags->flag_multi);
	}
	if ((flags->flag_err == 1 && nbr == 0) || (flags->flag_err == 0 && nbr == 1)){
		// ft_printf("1st Case\n");
		if (arg_list[i] != NULL){
			free(arg_list[i]);
			arg_list[i] = NULL;	
		}
		arg_list[i] = ft_strdup(".");
		// arg_list[i] = ".\0";
		// ft_printf("ARGLIST: %s\n", arg_list[i]);
	}
	else if (flags->flag_err == 0 && nbr > 1){
		// ft_printf("2nd Case\n");
		while(nbr > 1){
			if (arg_list[i] != NULL){
				free(arg_list[i]);
				arg_list[i] = NULL;
			}
			arg_list[i] = ft_strdup(av[i + 2]);
			i++;
			nbr -= 1;
		}
	}
	else if (flags->flag_err == 1 && nbr > 0){
		// ft_printf("3rd case\n");
		while (nbr > 0){
			if (arg_list[i] != NULL){
				free(arg_list[i]);
				arg_list[i] = NULL;
			}
			arg_list[i] = ft_strdup(av[i + 1]);
			i++;
			nbr -= 1;
		}
	}
}