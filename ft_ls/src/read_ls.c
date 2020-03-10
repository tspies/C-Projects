/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:12:02 by tspies            #+#    #+#             */
/*   Updated: 2020/03/10 14:46:44 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list       *get_stats(t_list *list)
{
    t_list  *tmp;
    
    tmp = list;
    while (list)
    {
        // ft_printf("%s\n", list->file->path);
        if (!(list->file->st = (t_stat *)malloc(sizeof(t_stat) * 1)))
            return (NULL);
        if ((lstat(list->file->path, list->file->st)) < 0)
        {
            return (NULL);
        }
        list = list->next;
    }
    list = tmp;
    return (list);
}

static t_list       *get_path(t_list *list, t_list *head, char *dir)
{
    char *half_name;
    char *full_name;

    list = head;
    while(list)
    {
        half_name = ft_strjoin("/", list->file->name);
        full_name = ft_strjoin(dir, half_name);
        list->file->path = ft_strdup(full_name);
        list = list->next;
    }
    list = head;
    return (list);
}

void		ft_ls(char *dir_name, t_flag *flags/*, int i*/)
{
    DIR             *dir;
    t_list          *list;
    t_list          *head; 
    struct dirent   *rent;

    list = NULL;
    dir = NULL;
    head = NULL;
    if (!(dir = opendir(dir_name)))
        broken();
    while ((rent = readdir(dir)))
    {
		if (flags->flag_a == 1 || (flags->flag_a == 0 && (ft_strncmp(rent->d_name, ".", 1)))){
        	list = (t_list *)ft_memalloc(sizeof(t_list) * 1);
        	list->file = (t_file *)ft_memalloc(sizeof(t_file) * 1);
        	list->file->name = (rent->d_name);
        	list->next = head;
        	head = list;
		}
    }
    list = head;
	//TODO: Check the -t flag against no sorting flags - r comes after t.
	//TODO: -l will be handled in the print output -a is already handled.
    sort_ascii(list, flags); 
    list = head;
    get_path(list, head, dir_name);
    get_stats(list);
	ft_printf("|---------->>>\n");
    print_list(list);
	ft_printf("|----------<<<\n\n");
	if (flags->flag_R == 1){
		recursion_start(dir_name, list, flags);
	}
}

void        read_dir_stream(char **arg_list, t_flag *flags)
{
	int i = 0;
	//int x = 10;
	while (arg_list[i]){
		ft_ls(arg_list[i], flags);
		i++;
	}
    // if (ac == 1)
    // {
	// 	ft_printf("1st Case\n");
    //     open_dir("."/*, flag*/);
    // }
    // else if (!(ft_strncmp(av[1][0], "-", 1)) && av[2] == NULL)
    // {
	// 	ft_printf("2nd Case\n");
    //     // ft_printf("AC Check: %d\n", ac);
    //     while (nbr_arg <= ac)
    //     {
    //         ft_printf("AV Check: %s | Nbr_arg: %d\n", av[nbr_arg], nbr_arg);
    //         open_dir(av[nbr_arg]/*, flag*/);
    //         nbr_arg++;
    //     }
    // }
	// else if (!())
}