/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:59:23 by tspies            #+#    #+#             */
/*   Updated: 2020/06/16 02:13:20 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static  void swap(t_list *curr, t_list *next){
	
	char *tmp = curr->name;
	curr->name = next->name;
	next->name = tmp;

	tmp = curr->path;
	curr->path = next->path;
	next->path = tmp;
}

t_list	*sort_time(t_list *list, char *dir){
	
	t_list	*head = list;
	t_list	*curr = NULL;
	t_stat	stat1;
	t_stat	stat2;
	
	curr = head;
	get_path(curr, dir);
		while(curr->next){

			lstat(curr->path, &stat1);
			lstat(curr->next->path, &stat2);
			// ft_printf("Enter Top\n");
			// 	ft_printf("Times: %ld ----- %ld\n", stat1.st_mtimespec.tv_sec, stat2.st_mtimespec.tv_sec);
			if (stat1.st_mtimespec.tv_sec < stat2.st_mtimespec.tv_sec){
					swap(curr, curr->next);
					curr = head;	
			}
			else if (stat1.st_mtimespec.tv_sec == stat2.st_mtimespec.tv_sec){
				// ft_printf("Comparing == %d\n", ft_strcmp(curr->file->name, curr->next->file->name));
					if (stat1.st_mtimespec.tv_nsec < stat2.st_mtimespec.tv_nsec){
						swap(curr, curr->next);
						curr = head;
					}
					else if (stat1.st_mtimespec.tv_nsec == stat2.st_mtimespec.tv_nsec){
						if (ft_strcmp(curr->name, curr->next->name) > 0){
							swap(curr, curr->next);
							curr = head;
						}
						else
							curr = curr->next;
						
					}
					else{
						// ft_printf("JUMP NEXT >>>\n\n");
						curr = curr->next;
					}
			}
			else{
				// ft_printf("JUMP NEXT BOTTOM>>>\n\n");
				curr = curr->next;
			}
		}	
	return(head);
}


t_list	*sort_rev(t_list *list){
	
	// ft_printf("IN Rev Sort\n");
	
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
		return(list);
}

t_list	*sorting_switchboard(t_list *list, char *dir_name, t_flag *flag){
	
		// ft_printf("=+=+=+=\n");
		// print_list(list);
		// ft_printf("=+=+=+=\n");
	// ft_putstr("IN SORT\n");
	t_list *tmp = list;
	
	// if(flag->flag_r == 1 && flag->flag_t == 0){
	// 	sort_rev(tmp);
	// }
	if(flag->flag_r == 0 && flag->flag_t == 1){
		sort_time(tmp, dir_name);		
	}
	else if (flag->flag_r == 1 && flag->flag_t == 1){
		// ft_printf("Reversed Time Sort\n");
		sort_time(tmp, dir_name);
	}
	else{
		sort_ascii(tmp);
	}
	
	return(tmp);
}
void	sort_ascii(t_list *list)
{
    char    *tmp;
    t_list  *list_head;

    list_head = list;
    tmp = NULL;
	// ft_printf("========\n");
	// print_list(list);
	// ft_printf("========\n");
    if (list)
    {
        while (list->next)
        {   
			// ft_printf("File %s----- Next: %s\n\n", list->name, list->next->name);
            if ((ft_strcmp(list->name, list->next->name)) > 0)
            {
                if (!(tmp = list->name))
					broken();
                if (!(list->name))
                    broken();
                if (!(list->name = list->next->name))
                    broken();
                if (!(list->next->name = tmp))
                    broken();
                list = list_head;
            }
            else{
				list = list->next;
			}
        }
    }
    list = list_head;
}