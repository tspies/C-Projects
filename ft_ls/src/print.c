/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:59:07 by tspies            #+#    #+#             */
/*   Updated: 2020/06/16 04:04:51 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list  *print_list(t_list *ls)
{
    t_list *tmp;

    tmp = ls;
	do{
        ft_printf("%s\n", ls->name);
        ls = ls->next;
	}while (ls);

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

void		print_handler(t_list *list, t_flag *flags, char *dir_name){
	
	t_list 				*head = list;
	struct 				stat file_stat;
	struct 				passwd	*usr;
	struct 				group	*grp;
	int					block_width_array[1000];
	int					block_init = 0;
	int					i = 0;
	char				*tmp = NULL;
	
	if (flags->flag_l == 1 && flags->flag_R == 0){
		// ft_printf("Long format print.\n\n");
		while(block_width_array[i]){
			block_width_array[i] = 0;
			i++;
		}
		i = 0;
		while(list){
			
			lstat(list->path, &file_stat);
			
			usr = getpwuid(file_stat.st_uid);
			grp = getgrgid(file_stat.st_gid);
			if ((!(usr->pw_name) || !(grp->gr_name)))
				return ;
			if ((size_t)block_width_array[0] < ft_strlen(usr->pw_name)){
				block_width_array[0] = (int)ft_strlen(usr->pw_name);
			}
			if ((size_t)block_width_array[1] < ft_strlen(grp->gr_name)){
				block_width_array[1] = (int)ft_strlen(grp->gr_name);
			}
			if ((S_ISCHR(file_stat.st_mode)) || (S_ISBLK(file_stat.st_mode))){
				tmp = ft_itoa(file_stat.st_rdev >> 24);
				if (ft_strlen(ft_itoa(block_width_array[2])) < ft_strlen(tmp)){
					free(tmp);
					tmp = NULL;
					tmp = ft_itoa(file_stat.st_rdev >> 24);
					block_width_array[2] = (int)ft_strlen(tmp);
					free(tmp);
					tmp = NULL;
				}
				if(tmp)
					free(tmp);
				tmp = ft_itoa(file_stat.st_rdev & 0xFFFFFF);
				if (ft_strlen(ft_itoa(block_width_array[3])) < ft_strlen(tmp)){
					free(tmp);
					tmp = NULL;
					tmp = ft_itoa(file_stat.st_rdev & 0xFFFFFF);
					block_width_array[3] = (int)ft_strlen(tmp);
					free(tmp);
					tmp = NULL;
				}
				if(tmp != NULL)
					free(tmp);
			}
			else{
				tmp = ft_itoa(file_stat.st_size);
				if (block_width_array[2] < (int)ft_strlen(tmp)){
					free(tmp);
					tmp = NULL;
					tmp = ft_itoa(file_stat.st_size);
					block_width_array[2] = (int)ft_strlen(tmp);
					free(tmp);
					tmp = NULL;
				}
				if(tmp != NULL){
					free(tmp);
					tmp = NULL;
				}
			}
			block_init  += (int)(file_stat.st_blocks);
			list = list->next;
		}
		list = head;
		
		ft_printf("total %d\n", block_init);
		while (list){
			print_long_format(list->path, list->name, block_width_array);
			list = list->next;	
		}
		list = head;
	}
	else if (flags->flag_R == 1 && flags->flag_l == 0){
		// ft_printf("Recursion Print!\n\n");
		if (ft_strcmp(dir_name, ".") != 0)
			ft_printf("\n%s:\n", dir_name);
		print_list(list);
	}
	else if (flags->flag_R == 1 && flags->flag_l== 1){
		// ft_printf("Recursion and Long format Print!\n\n");
		if (ft_strcmp(dir_name, ".") != 0)
			ft_printf("\n%s:\n", dir_name);
		
		lstat(list->path, &file_stat);
		block_init = build_block_width_array(list, file_stat, block_width_array, block_init);
		ft_printf("total %d\n", block_init);
		while (list){
			print_long_format(list->path, list->name, block_width_array);
			list = list->next;	
		}
		list = head;
			
	}
	else{
		if (flags->flag_multi == 1)
			ft_printf("%s:\n", dir_name);
		// ft_printf("Standard Print!\n");
		print_list(list);
		if (flags->flag_multi == 1)
			ft_printf("\n");
		// ft_printf("|---------->>>\n");
		// print_list(list);
		// ft_printf("|---------->>>\n\n");
	}
	// ft_putstr("MARL EXIT PRINT\n");
}

int		build_block_width_array(t_list *list, struct stat file_stat, int *block_width_array, int block_init){
		
		struct 	passwd	*usr;
		struct 	group	*grp;
		t_list			*head = list;
		
		block_init = 0;
		while(block_width_array[block_init]){
			block_width_array[block_init] = 0;
			block_init++;
		}
		block_init = 0;
		while(list){
			
			lstat(listgit->path, &file_stat);
			usr = getpwuid(file_stat.st_uid);
			grp = getgrgid(file_stat.st_gid);
			// ft_printf("MARK\n");
			if ((size_t)block_width_array[0] < ft_strlen(usr->pw_name)){
				block_width_array[0] = (int)ft_strlen(usr->pw_name);
			}
			if ((size_t)block_width_array[1] < ft_strlen(grp->gr_name)){
				block_width_array[1] = (int)ft_strlen(grp->gr_name);
			}
			if ((S_ISCHR(file_stat.st_mode)) || (S_ISBLK(file_stat.st_mode))){
				if (ft_strlen(ft_itoa(block_width_array[2])) < ft_strlen(ft_itoa(file_stat.st_rdev >> 24)))
					block_width_array[2] = (int)ft_strlen(ft_itoa(file_stat.st_rdev >> 24));
				if (ft_strlen(ft_itoa(block_width_array[3])) < ft_strlen(ft_itoa(file_stat.st_rdev & 0xFFFFFF)))
					block_width_array[3] = (int)ft_strlen(ft_itoa(file_stat.st_rdev & 0xFFFFFF));
			}
			else{
				if ((size_t)block_width_array[2] < ft_strlen(ft_itoa(file_stat.st_size)))
					block_width_array[2] = (int)ft_strlen(ft_itoa(file_stat.st_size));
			}
			block_init  += file_stat.st_blocks;
			list = list->next;
		}
		list = head;
		return(block_init);
}

