/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 03:12:28 by tristyn           #+#    #+#             */
/*   Updated: 2020/01/24 22:28:36 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		is_valid_flag(char c, t_flag *flags)
{
	if (c == 'a' || c == 'l' || c == 't' || c == 'r' || c == 'R')
		flags->flag_err = 0;
	else
	{
		flags->flag_err = 1;
		flag_err_msg(c);
	}
}

t_flag		*flag_check(t_flag *flags, char **av)
{
	int		x;
	int		y;

	x = 1;
	while (av[x] && av[x][0] == '-')
	{
		y = 1;
		while (av[x][y])
		{
			is_valid_flag(av[x][y], flags);
			if (av[x][y] == 'a'){
				flags->flag_a = 1;
				flags->flag_err = 0;
			}
			if (av[x][y] == 'l')
			{
				flags->flag_l = 1;
				flags->flag_err = 0;
			}
			if (av[x][y] == 't'){
				flags->flag_t = 1;
				flags->flag_err = 0;
			}
			if (av[x][y] == 'r'){
				flags->flag_r = 1;
				flags->flag_err = 0;
			}
			if (av[x][y] == 'R'){
				flags->flag_R = 1;
				flags->flag_err = 0;
			}
				y++;
		}
		x++;
	}
	return (flags);
}


static t_file 		*initialize_node(t_file *ls)
{
	ls = ((t_file *)malloc(sizeof(t_file) * 1));
	if (!(ls))
		return (NULL);
	ls->name = NULL;
	ls->path = NULL;
	ls->st = NULL;
	return (ls);
}

static t_flag *flag_start(t_flag *flag)
{
	flag->flag_a = 0;
	flag->flag_l = 0;
	flag->flag_t = 0;
	flag->flag_r = 0;
	flag->flag_R = 0;
	flag->flag_err = 1;
	return (flag);
}

t_flag		*ft_initialize_ls(int ac, char **av)
{
	t_file	*ls_node;
	t_flag	*flags;

	flags = NULL;
	ls_node = NULL;
	if (!(flags = (t_flag *)malloc(sizeof(t_flag) * 1)))
		broken();
	flags = flag_check(flag_start(flags), av);
	// ft_printf("FLAG LIST:\n a:  %u\n l:  %u\n t:  %u\n r:  %u\n R:  %u\n", flags->flag_a, flags->flag_l, flags->flag_t, flags->flag_r, flags->flag_R);
	if (!(ls_node = initialize_node(ls_node)))
		broken();
	return (flags);
}