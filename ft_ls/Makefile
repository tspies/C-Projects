# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tristyn <tristyn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/31 12:24:51 by tspies            #+#    #+#              #
#    Updated: 2020/06/16 14:59:46 by tristyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC_PATH = src/
OBJ_PATH = obj/
LIB_PATH = libft/

CC = gcc
FLAGS += -Wall -Wextra -Werror -g
FLAGS += -I ./includes/ -I ./$(LIB_PATH)includes/

SRC_LIST = ft_initialize_ls.c \
			read_ls.c \
			error_output.c \
			sorting.c \
			print.c \
			print_long.c \
			main.c \
			args.c \
			recursion.c
			
SRC = $(addprefix $(SRC_PATH), $(SRC_LIST))
OBJ = $(addprefix $(OBJ_PATH), $(SRC_LIST:.c=.o))

# Clours #
R = \033[0;31m
B = \033[0;34m
G = \033[0;32m
Y = \033[0;33m
BR = \033[1;31m
BG = \033[1;32m
BB = \033[1;34m
SET = \033[0m

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@echo "$(G)Libft Makefile Running..."
	@echo "$(G)Compliling All $(BB).c $(G)Files...$(SET)"
	@echo "$(G)Compliling All $(BB).o $(G)Files...$(SET)"
	@echo "$(G)Creating $(BR)Libft.a $(G)Library$(SET)"
	@echo "$(G)Binary $(BR)Libft.a $(G)Created!$(SET)"
	@$(CC) $(FLAGS) $(OBJ) -L $(LIB_PATH) -lft -o $(NAME)
	@echo "\033[32mBinary \033[1;31m$(NAME)\033[0m\033[32m Fused With Libft.a\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p obj
	@$(CC) -c $(FLAGS) $< -o $@
	@echo "\033[34m\033[1mCompiling \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	@make -C $(LIB_PATH)/ clean
	@echo "$(G)Cleaning $(BB)Libft $(G)Files..."
	@/bin/rm -rf obj
	@sleep 0.5
	@echo "$(G)Cleaning $(BB)ft_ls $(G)Files..."
	@sleep 0.5
	@echo "$(Y)Done!$(SET)"

fclean:
	@make -C $(LIB_PATH)/ fclean
	@echo "$(G)Cleaning $(BB)Libft $(G)Files..."
	@/bin/rm -rf $(NAME)
	@sleep 0.5
	@echo "$(G)Cleaning $(BB)ft_ls $(G)Files..."
	@sleep 0.5
	@echo "$(G)Removing Binary $(BB)ft_ls$(G)..."
	@sleep 0.5
	@echo "$(Y)Done!$(SET)"	

re: fclean all