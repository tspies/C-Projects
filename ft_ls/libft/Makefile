# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tspies <tspies@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 07:44:52 by tspies            #+#    #+#              #
#    Updated: 2018/09/28 11:38:08 by tspies           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PATH = src

CC = gcc
FLAGS += -Wall -Werror -Wextra -g
FLAGS += -I includes

SRCS = 	ft_strlen.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strdup.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strncat.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_intlen.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_isspace.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putnbr.c\
		ft_memset.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_bzero.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strlcat.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strrev.c\
		ft_strsplit.c\
		ft_arrstr.c\
		ft_wdcount.c \
		ft_printf.c \
		parse_switchboard.c \
		specifier_switchboard.c \
		unsigned_len.c \
		signed_len.c \
		handle_c.c \
		handle_d.c \
		handle_u.c \
		handle_s.c \
		handle_o.c \
		handle_x.c \
		handle_p.c \
		wchar_len.c \
		ptr_len.c \
		ft_put_wchar.c \
		ft_put_wstr.c \
		zero_check.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_fatoi.c \
		ft_fstrchr.c \
		ft_fstrlen.c \
		ft_put_percent.c \


.PHONY: clean fclean all re

LIB_SRC = $(addprefix $(PATH)/, $(SRCS))

OBJS =	$(LIB_SRC:.c=.o)

all: $(NAME)

$(OBJS): %.o : %.c
	@$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

exec:
	@gcc $(FLAGS) -L. libft.a main.c

local:
	@gcc main.c $(NAME)

norm:
	@norminette -R CheckForbiddenSourceHeader *.c

