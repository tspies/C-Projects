/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:12:02 by tspies            #+#    #+#             */
/*   Updated: 2020/06/16 03:02:58 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// static t_list       *get_stats(t_list *list)
// {
//     t_list  *tmp;
    
//     tmp = list;
//     while (list)
//     {
//         if (!(list->file->st = (t_stat *)malloc(sizeof(t_stat) * 1)))
//             return (NULL);
//         if ((lstat(list->file->path, list->file->st)) < 0)
//         {
//             return (NULL);
//         }
//         list = list->next;
//     }
//     list = tmp;
//     return (list);
// }

t_list       *get_path(t_list *list, char *dir)
{
    char *half_name = NULL;
    char *full_name = NULL;
	t_list	*head;

    head = list;
    while(list)
    {
        half_name = ft_strjoin("/", list->name);
        full_name = ft_strjoin(dir, half_name);
		// ft_printf("Full Name: %s\n", full_name);
		if(list->path != NULL){
			free(list->path);
			list->path = NULL;
		}
        list->path = ft_strdup(full_name);
        list = list->next;
		if (half_name != NULL)
			free(half_name);
		if (full_name != NULL)
			free(full_name);
    }
    list = head;
	
	// ft_putstr("MARK END\n");
    return (list);
}

void		ft_ls(t_list *list, char *dir_name, t_flag *flags)
{
	get_path(list, dir_name);
	print_handler(list, flags, dir_name);
}

void	read_dir_stream(char *arg_list, t_flag *flags)
{
	t_list 			*list_head = NULL;
	t_list			*list_curr = NULL;
	t_list			*list_tmp = NULL;
	t_list 			*list = NULL;
	// t_list 			*head = NULL;
	int				first = 0;
	DIR            	*dir = NULL;
	struct dirent 	*rent = NULL;

		// while(arg_list[i]){
		// 	ft_printf("===\n");
		// 	ft_printf("%s\n", arg_list[i]);
		// 	ft_printf("===\n");
		// 	i++;
		// }
		// i = 0;
		if (flags->flag_R == 1)
			recursion_start(arg_list, flags);				
		else{
			// list_head  = (t_list *)malloc(sizeof(t_list));
			// list = list_head;

			if (!(dir = opendir(arg_list)))
        		no_dir_or_file_error(arg_list);
			while ((rent = readdir(dir))){

					if (flags->flag_a == 1 || (flags->flag_a == 0 && (ft_strncmp(rent->d_name, ".", 1)))){

						list_curr = (t_list *)malloc(sizeof(t_list));
						list_curr->name = ft_strdup(rent->d_name);
						list_curr->path = NULL;
						
						if(first == 0){
							list_head = list_tmp = list_curr;
							// ft_printf("Debug: name -> %s\n", rent->d_name);
							// ft_printf("<-( %s )->\n", list_tmp->name);
							first = 1;
						}
						else{
							// ft_printf("ELSE NODE\n");
							list_tmp->next = list_curr;
							list_tmp = list_curr;
							// ft_printf("<-( %s )->\n", list_tmp->name);
						}	
					}
			}
			list_tmp->next = NULL;
			list_tmp = list_head;
			closedir(dir);
			// ft_printf("MARK --\n");
			// ft_printf("\n[%s]\n\n", arg_list);
			// ft_printf("FLAG CHECK %d\n", flags->flag_a);
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
			
			ft_ls(list, arg_list, flags);
			free_list(list, list_head);
		}
}

void	free_list(t_list *list, t_list *list_head){
	
	t_list *tmp;

	while(list){
		free(list->name);
		list->name = NULL;
		free(list->path);
		list->path = NULL;
		tmp = list->next;
		free(list);
		list = NULL;
		list = tmp;
	}
	list_head = NULL;
}