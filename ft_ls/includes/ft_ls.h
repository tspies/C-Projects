/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:59:21 by tspies            #+#    #+#             */
/*   Updated: 2020/01/28 09:39:00 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
**	------->Libraries<-------
*/

# include "libft.h"
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <string.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>

# define unsigned int u_int;
# define NAME "ft_ls"

typedef struct	stat 	t_stat;
typedef struct	s_flags
{
	u_int	flag_a;
	u_int	flag_l;
	u_int	flag_t;
	u_int	flag_r;
	u_int	flag_R;
	u_int	flag_err;
}				t_flag;

typedef struct s_file 
{
	char			*name;
	char			*path;
	t_stat			*st;
}				t_file;

typedef struct	s_list
{
	struct s_file	*file;
	struct s_list	*next;
}			t_list;

/*
** ------->FUNCTIONS<-------
**
**		-->initialize<--
*/
t_flag			*ft_initialize_ls(int ac, char **av);
void        	read_dir_stream(char **arg_list, t_flag *flags);
t_list  		*sort_ascii(t_list *list, t_flag *flag);
t_list  		*print_list(t_list *ls);
void			print_args(char **arg_list);
void			ft_ls(char *dir_name, t_flag *flags/*, int i*/);
void			recursion_start(char *dir_name, t_list *list, t_flag *flags/*, int i*/);

/*
**		-->error output<--
*/
void    		flag_err_msg(char c); 
void			broken(void);
void			straight_exit(void);

// Arguments
int				arg_nbr_check(int ac, char **av);
char			**parse_args(int nbr, t_flag *flags, char **av);

// Recursion
int		root_dir_path(char *name);
#endif
