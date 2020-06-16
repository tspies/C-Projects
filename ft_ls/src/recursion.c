/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:42:02 by tristyn           #+#    #+#             */
/*   Updated: 2020/06/16 03:59:21 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		root_dir_name(char *name){
	// ft_printf("String comarison: %s == %d\n", name, ft_strncmp(name, ".", 1));
	if ((ft_strncmp(name, ".", 1) != 0) && (ft_strncmp(name, "..", 2) != 0))
		return 1;
	return 0;
}
void	recursion_start(char *arg_list, t_flag *flags){
	
	t_list			*head = NULL;
	t_list			*list = NULL;
	t_list			*tmp_list = NULL;
	t_list 			*list_head = NULL;
	t_list			*list_curr = NULL;
	t_list			*list_tmp = NULL;
	t_stat			stat;
	DIR            	*dir = NULL;
	int				first = 0;
	char			*tmp_path = NULL;
	struct dirent 	*rent = NULL;

	if ((dir = opendir(arg_list))){
		while ((rent = readdir(dir))){
			// ft_printf("RENT DNAME: %s\n\n", rent->d_name);
				if (flags->flag_a == 1 || (flags->flag_a == 0 && (ft_strncmp(rent->d_name, ".", 1)))){
					
					list_curr = (t_list *)malloc(sizeof(t_list));
					list_curr->name = ft_strdup(rent->d_name);
					list_curr->path = NULL;
					
					if (first == 0){
						list_head = list_tmp = list_curr;
						first = 1;
					}
					else{
						list_tmp->next = list_curr;
						list_tmp = list_curr;
					}
				}
		}
		list_tmp->next = NULL;
		list_tmp = list_head;
		closedir(dir);
		// ft_printf(" RECURSION MARKER\n\n");
		list = list_tmp;
		sorting_switchboard(list, arg_list, flags);
		if (flags->flag_r == 1){
			t_list	*next = NULL;
			t_list	*curr = list;
			t_list	*prev = NULL;
		
			while (curr){
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			list = prev;	
		}

		get_path(list, arg_list);
		ft_ls(list, arg_list, flags);
		head = list;
		while(list){
			// ft_printf("In while loop, mode: %d name: %s\n", S_ISDIR(list->file->st->st_mode), list->file->name);
			// ft_printf("Enter While\n\n");
			// ft_printf("Current File Path: %s\n\n", list->file->path);
			if ((lstat(list->path, &stat) == 0)){
				if (S_ISDIR(stat.st_mode) && root_dir_name(list->name)){
					// ft_printf("Dir Found: [%s] with path --> %s\n", list->file->name, list->file->path);
					// ft_printf("FREE IN DIR\n");
					tmp_list = list->next;
					if(tmp_path != NULL){
						free(tmp_path);
						tmp_path = NULL;
					}
					tmp_path = ft_strdup(list->path);
					free(list->name);
					list->name = NULL;
					free(list->path);
					list->path = NULL;
					free(list);
					list = NULL;
					recursion_start(tmp_path, flags);
				}
				else{
					// ft_putstr("NEXT NODE FREE\n");
					tmp_list = list->next;
					// ft_putstr("MARK\n");
					if (list->name){
						free(list->name);
						list->name = NULL;
					}
					if (list->path){
						free(list->path);
						list->path = NULL;	
					}
					if (list){
						free(list);
						list = NULL;
					}
				}
				if (tmp_path != NULL){
					free(tmp_path);
					tmp_path = NULL;
				}
				list = tmp_list;
					// if (tmp_path != NULL)
					// 	free(tmp_path);
					}
			// ft_printf("[ %s ]\nRoot_dir_name Output: %d\n ISDIR = %d\n\n", list->file->name, root_dir_name(list->file->name), S_ISDIR(stat.st_mode));
			// ft_printf("File , flagsFound: %s\n", list->file->name);
			
		}
		// ft_putstr("END REC\n");
		// free_list_a(list, list_head);
		list = tmp_list;
	}
	else
		no_dir_or_file_error(arg_list);
	// ft_printf("EXIT WHILE\n\n");
}

void	free_list_a(t_list *list, t_list *list_head){
	
	t_list	*tmp = NULL;
	t_list	*lst = list_head;

	lst = NULL;

	while(list){
		if (list->file->name)
			free(list->file->name);
		if (list->file->path)
			free(list->file->path);
		if (list->file)
			free(list->file);
		tmp = list->next;
		if (list)
			free(list);
		list = tmp;
	}
	// free(list_head);
}