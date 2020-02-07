/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 22:01:39 by tristyn           #+#    #+#             */
/*   Updated: 2020/01/24 23:55:58 by tristyn          ###   ########.fr       */
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

char	**parse_args(int nbr, t_flag *flags, char **av){
	int 	i = 0;
	char	**arg_list;
	arg_list = (char **)malloc(sizeof(char) * 999999);
	if ((flags->flag_err == 1 && nbr == 0) || (flags->flag_err == 0 && nbr == 1)){
		ft_printf("1st Case\n");
		arg_list[i] = strdup(".");
	}
	else if (flags->flag_err == 0 && nbr > 1){
		ft_printf("2nd Case\n");
		while(nbr > 1){
			arg_list[i] = strdup(av[i + 2]);
			i++;
			nbr -= 1;
		}
	}
	else if (flags->flag_err == 1 && nbr > 0){
		ft_printf("3rd case\n");
		while (nbr > 0){
			arg_list[i] = strdup(av[i + 1]);
			i++;
			nbr -= 1;
		}
	}
	return arg_list;
}