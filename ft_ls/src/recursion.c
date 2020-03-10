/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:42:02 by tristyn           #+#    #+#             */
/*   Updated: 2020/03/10 14:24:34 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		root_dir_name(char *name){
	// ft_printf("String comarison: %s == %d\n", name, ft_strncmp(name, ".", 1));
	if ((ft_strncmp(name, ".", 1) != 0) && (ft_strncmp(name, "..", 2) != 0))
		return 1;
	return 0;
}
void	recursion_start(char *dir_name, t_list *list, t_flag *flags/*, int i*/){
	t_list	*head;
	head = list;
	while(list){
		// ft_printf("In while loop, mode: %d name: %s\n", S_ISDIR(list->file->st->st_mode), list->file->name);
		// ft_printf("[ %s ]\nRoot_dir_name Output: %d\n ISDIR = %d\n\n", list->file->name, root_dir_name(list->file->name), S_ISDIR(list->file->st->st_mode));
		if (S_ISDIR(list->file->st->st_mode) && root_dir_name(list->file->name)){
			ft_printf("Dir Found: [%s] with path --> %s\n", list->file->name, list->file->path);
			if (root_dir_name(list->file->name))
				ft_ls(list->file->path, flags);
		}
			// ft_printf("File Found: %s\n", list->file->name);
		if (list->next)
			list = list->next;
		else
			list = NULL;
	}
	list = head;
}