/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:59:23 by tspies            #+#    #+#             */
/*   Updated: 2020/01/28 10:20:46 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// static  t_list *sort_rev(t_list *ls)
// {
//     char    *tmp;
//     t_list  *tmp_ls;

//     tmp_ls = NULL;
//     while (ls)
//     {
//         if ((ft_strcmp(ls->file->name, ls->next->file->name)) < 0)
//         {
//             tmp = ft_strdup(ls->file->name);
//             ls->file->name = ft_strdup(ls->next->file->name);
//             ls->next->file->name = ft_strdup(tmp);
//             ls = tmp_ls;
//         }
//         else
//             ls = ls->next;
//     }
//     return (ls);
// }

t_list  *sort_ascii(t_list *list, t_flag *flag)
{
    char    *tmp;
    t_list  *list_head;

    list_head = list;
    tmp = NULL;
    if (list)
    {
		ft_printf("---------->>>\n");
        print_list(list);
		ft_printf("----------<<<\n");
        while (list)
        {   
            // write(1, "IN WHILE\n", 9);
            // print_list(list);
            if ((ft_strcmp(list->file->name, list->next->file->name)) > 0)
            {
                // print_list(ls);
                ft_printf("-------------\n");
				ft_printf("Swapping CURRENT: %s with NEXT: %s\n", list->file->name, list->next->file->name);
                if (!(tmp = ft_strdup(list->file->name)))
                    ft_printf("TMP FAIL\n");
                if (!(list->file->name))
                    ft_printf("FALSE NAME\n");
                if (!(list->file->name = ft_strdup(list->next->file->name)))
                    ft_printf("NAME FAIL\n");
                if (!(list->next->file->name = ft_strdup(tmp)))
                    ft_printf("NEXT FAIL\n");
				ft_printf("CURRENT: %s, NEXT: %s\n", list->file->name, list->next->file->name);
				ft_printf("---------->>>\n");
        		print_list(list);
				ft_printf("----------<<<\n");
                list = list_head;
            }
            else{
				ft_printf("File: %s NEXT: %s\n", list->file->name, list->next->file->name);
				list = list->next;
			}
        }
		ft_printf("---------->>>\n");
        print_list(list);
		ft_printf("----------<<<\n");
        // ft_printf("%s\n", list->file->name);
        // if (!list)
        //     ft_printf("NULL LIST\n");
        // list = tmp_ls;
        // print_list(ls);
    }
    list = list_head;
    return (list);
}