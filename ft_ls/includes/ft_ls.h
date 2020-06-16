/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:59:21 by tspies            #+#    #+#             */
/*   Updated: 2020/06/16 19:04:47 by tristyn          ###   ########.fr       */
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

extern int first;

typedef struct	stat 	t_stat;
typedef struct	s_flags
{
	u_int	flag_a;
	u_int	flag_l;
	u_int	flag_t;
	u_int	flag_r;
	u_int	flag_R;
	u_int	flag_err;
	u_int	flag_multi;
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
	char			*name;
	char			*path;
	struct s_list	*next;
}			t_list;

/*
** ------->FUNCTIONS<-------
**
**		-->initialize<--
*/
void			ft_initialize_ls(char **av, t_flag *flags);
void        	read_dir_stream(char *arg_list, t_flag *flags);
void			ft_ls(t_list* list, char *dir_name, t_flag *flags);
void			recursion_start(char *arg_list, t_flag *flags);

/*
**		-->error output<--
*/
void    		flag_err_msg(char c); 
void			broken(void);
void			straight_exit(void);
void			no_dir_or_file_error(char *dir_or_file_name);

// Arguments
int				arg_nbr_check(int ac, char **av);
void			parse_args(int nbr, t_flag *flags, char **av, char **arg_list);

// Recursion
int				root_dir_path(char *name);

// Sorting
void	  		sort_ascii(t_list *list);
t_list			*sorting_switchboard(t_list *list, char *dir_name, t_flag *flag);
t_list			*sort_rev(t_list *list);
t_list			*sort_time(t_list *list, char* dir);
t_list       	*get_path(t_list *list, char *dir);

// Printing
void 			print_handler(t_list *list, t_flag *flags, char * dir_name);
void			print_args(char **arg_list);
t_list  		*print_list(t_list *ls);

// Print Long
void			print_file_rights(struct stat file_stat);
void			print_file_links(struct stat file_stat);
void			print_file_type(struct stat file_stat);
void			print_file_id(struct stat file_stat, int *block_width_array);
void			print_long_format(char *file_path, char *file_name, int *block_width_array);
void			print_file_minor(struct stat file_stat, int *block_width_array);
void			print_file_major(struct stat file_stat, int *block_width_array);
void			print_file_time(struct stat file_stat);
int				build_block_width_array(t_list *list, struct stat file_stat, int *block_width_array, int block_init);

//MISC
void			set_all_to_null(char **arg_list);
void			free_list_a(t_list *list, t_list *list_head);
void			free_list(t_list *list, t_list *list_head);
#endif
