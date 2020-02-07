/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 07:18:43 by tspies            #+#    #+#             */
/*   Updated: 2018/06/25 08:03:30 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/Includes/libft.h"
#include <stdio.h>
#include <fcntl.h>

int		get_next_line(int fd, char **line)
{
	char			*buff;
	int				byte;
	char			*tmp;
	static char		*save;

	if (fd < 0)
		return (-1);
	if (read(fd, NULL, 0) < 0)
		return (-1);
	buff = ft_strnew(BUFF_SIZE);
	if (!save)
		save = ft_strnew(0);
	while (!(ft_strchr(save, '\n')))
	{
		byte = read(fd, buff, BUFF_SIZE);
		tmp = save;
		save = ft_strjoin(tmp, buff);
		free(tmp);
		ft_strclr(buff);
		if (!byte)
			break ;
	}
	if (buff)
		ft_strdel(&buff);
	if (!(ft_strchr(save, '\n')))
	{
		*line = save;
		save = ft_strnew(0);
	}
	else
	{
		*line = ft_strnew(ft_strchr(save, '\n') - save);
		ft_strncpy(*line, save, ft_strchr(save, '\n') - save);
		tmp = save;
		save = ft_strsub(save, (ft_strchr(save, '\n') - save) + 1,
				(ft_strlen(save) - (ft_strchr(save, '\n') - save)));
		free(tmp);
	}
	if (byte || ft_strlen(*line) || ft_strlen(save))
		return (1);
	else
		return (0);
	return (0);
}
