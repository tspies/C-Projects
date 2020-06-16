/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:59:07 by tspies            #+#    #+#             */
/*   Updated: 2020/06/16 20:26:11 by tristyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_long_format(char *file_path, char *file_name, int *block_width_array){

	struct	stat 	file_stat;
	int				spacing = 0;
	char			*tmp = NULL;

	if ((lstat(file_path, &file_stat)) < 0)
		return ;
	print_file_type(file_stat);
	print_file_rights(file_stat);
	print_file_links(file_stat);
	print_file_id(file_stat, block_width_array);
	if (!(S_ISCHR(file_stat.st_mode)) && !(S_ISBLK(file_stat.st_mode))){
		if (block_width_array[3] == 0){
			tmp = ft_itoa(file_stat.st_size);
			spacing = block_width_array[2] - (int)ft_strlen(tmp) - 1;
			free(tmp);
		}
		else
			spacing = (block_width_array[2] + block_width_array[3]) + 1;
		while(spacing > -1){
			ft_putchar(' ');
			spacing--;
		}
		ft_putnbr(file_stat.st_size);
	}
	else{
			print_file_major(file_stat, block_width_array);
			print_file_minor(file_stat, block_width_array);
			
	}
	print_file_time(file_stat);
	ft_printf("%s\n", file_name);
}


void	print_file_type(struct stat file_stat){
	
	// ft_printf("MODE: %ld\n", file_stat.st_mode);
	if (S_ISDIR(file_stat.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(file_stat.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(file_stat.st_mode))
		ft_putchar('b');
	else if (S_ISLNK(file_stat.st_mode))
		ft_putchar('l');
	else if (S_ISFIFO(file_stat.st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(file_stat.st_mode))
		ft_putchar('s');
	else if (S_ISREG(file_stat.st_mode))
		ft_putchar('-');
}

void	print_file_rights(struct stat file_stat){
	
	ft_putstr((file_stat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((file_stat.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((file_stat.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXOTH) ? "x" : "-");
	ft_putstr("  ");
}

void	print_file_links(struct stat file_stat){
	if ((file_stat.st_nlink) < 10)
		ft_putstr(" ");
	ft_putnbr(file_stat.st_nlink);
	ft_putchar(' ');
}

void	print_file_id(struct stat file_stat, int *block_width_array){
	
	struct passwd	*usr;
	struct group	*grp;
	int				spacing = 0;

	usr = getpwuid(file_stat.st_uid);
	spacing = block_width_array[0] - ft_strlen(usr->pw_name);
	ft_putstr(usr->pw_name);
	while(spacing > -2){
		ft_putchar(' ');
		spacing--;
	}
	grp = getgrgid(file_stat.st_gid);
	spacing = block_width_array[1] - ft_strlen(grp->gr_name);
	ft_putstr(grp->gr_name);
	while(spacing > -2){
		ft_putchar(' ');
		spacing--;
	}
}

void	print_file_major( struct stat file_stat, int *block_width_array){

	int spacing = 0;
	
	spacing = block_width_array[2] - (int)(ft_strlen(ft_itoa((file_stat.st_rdev >> 24))));
	while(spacing > -1){
		ft_putchar(' ');
		spacing--;
	}
	ft_printf("%d,", file_stat.st_rdev >> 24);
}

void	print_file_minor(struct stat file_stat, int *block_width_array){

	int spacing = 0;
	
	spacing = block_width_array[3] - (int)ft_strlen(ft_itoa(file_stat.st_rdev & 0xFFFFFF));
	while(spacing > -1){
		ft_putchar(' ');
		spacing--;;
	}
	ft_printf("%d", file_stat.st_rdev & 0xFFFFFF);
}

void	print_file_time(struct stat file_stat){
	
	// time_t 	now;
	char 	*seconds;

	// time(&now);
	seconds = ctime(&(file_stat.st_mtimespec.tv_sec)) + 4;
	ft_printf(" %.12s ", seconds);
}