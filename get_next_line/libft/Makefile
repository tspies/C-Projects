# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tspies <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 07:44:52 by tspies            #+#    #+#              #
#    Updated: 2018/06/06 15:33:33 by tspies           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PATH = ./

CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = -I ./Includes

SRCS = 	$(PATH)ft_strlen.c\
		$(PATH)ft_strcpy.c\
		$(PATH)ft_strncpy.c\
		$(PATH)ft_strcat.c\
		$(PATH)ft_strdup.c\
		$(PATH)ft_strstr.c\
		$(PATH)ft_strnstr.c\
		$(PATH)ft_strncat.c\
		$(PATH)ft_atoi.c\
		$(PATH)ft_itoa.c\
		$(PATH)ft_intlen.c\
		$(PATH)ft_isalpha.c\
		$(PATH)ft_isdigit.c\
		$(PATH)ft_isalnum.c\
		$(PATH)ft_isascii.c\
		$(PATH)ft_isprint.c\
		$(PATH)ft_isspace.c\
		$(PATH)ft_toupper.c\
		$(PATH)ft_tolower.c\
		$(PATH)ft_putchar.c\
		$(PATH)ft_putstr.c\
		$(PATH)ft_putchar_fd.c\
		$(PATH)ft_putstr_fd.c\
		$(PATH)ft_putendl.c\
		$(PATH)ft_putendl_fd.c\
		$(PATH)ft_putnbr_fd.c\
		$(PATH)ft_putnbr.c\
		$(PATH)ft_memset.c\
		$(PATH)ft_memcpy.c\
		$(PATH)ft_memccpy.c\
		$(PATH)ft_memchr.c\
		$(PATH)ft_memcmp.c\
		$(PATH)ft_memmove.c\
		$(PATH)ft_memalloc.c\
		$(PATH)ft_memdel.c\
		$(PATH)ft_bzero.c\
		$(PATH)ft_strcmp.c\
		$(PATH)ft_strncmp.c\
		$(PATH)ft_strchr.c\
		$(PATH)ft_strrchr.c\
		$(PATH)ft_strlcat.c\
		$(PATH)ft_strnew.c\
		$(PATH)ft_strdel.c\
		$(PATH)ft_strclr.c\
		$(PATH)ft_striter.c\
		$(PATH)ft_striteri.c\
		$(PATH)ft_strmap.c\
		$(PATH)ft_strmapi.c\
		$(PATH)ft_strequ.c\
		$(PATH)ft_strnequ.c\
		$(PATH)ft_strsub.c\
		$(PATH)ft_strjoin.c\
		$(PATH)ft_strtrim.c\
		$(PATH)ft_strrev.c\
		$(PATH)ft_strsplit.c\
		$(PATH)ft_arrstr.c\
		$(PATH)ft_wdcount.c


OBJS =	ft_strlen.o\
		ft_strcpy.o\
		ft_strncpy.o\
		ft_strcat.o\
		ft_strdup.o\
		ft_strstr.o\
		ft_strnstr.o\
		ft_strncat.o\
		ft_atoi.o\
		ft_itoa.o\
		ft_intlen.o\
		ft_isalpha.o\
		ft_isdigit.o\
		ft_isalnum.o\
		ft_isascii.o\
		ft_isprint.o\
		ft_isspace.o\
		ft_toupper.o\
		ft_tolower.o\
		ft_putchar.o\
		ft_putstr.o\
		ft_putchar_fd.o\
		ft_putstr_fd.o\
		ft_putendl.o\
		ft_putendl_fd.o\
		ft_putnbr_fd.o\
		ft_putnbr.o\
		ft_memset.o\
		ft_memcpy.o\
		ft_memccpy.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_memmove.o\
		ft_memalloc.o\
		ft_memdel.o\
		ft_bzero.o\
		ft_strcmp.o\
		ft_strncmp.o\
		ft_strchr.o\
		ft_strrchr.o\
		ft_strlcat.o\
		ft_strnew.o\
		ft_strdel.o\
		ft_strclr.o\
		ft_striter.o\
		ft_striteri.o\
		ft_strmap.o\
		ft_strmapi.o\
		ft_strequ.o\
		ft_strnequ.o\
		ft_strsub.o\
		ft_strjoin.o\
		ft_strtrim.o\
		ft_strrev.o\
		ft_strsplit.o\
		ft_arrstr.o\
		ft_wdcount.o

all: $(NAME)

$(NAME):
	$(CC) -c $(FLAGS) $(HEADER) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

exec:
	gcc $(FLAGS) -L. libft.a main.c

local:
	gcc main.c $(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader *.c

.PHONY: clean fclean all re
