
NAME = libftprintf.a

S_PATH = src
L_PATH = libft

CC =	gcc
FLAGS +=	-Wall -Wextra -Werror
FLAGS +=	-Iincludes

LIB_SRC	=	ft_strlen.c \
				ft_strchr.c \
				ft_putstr.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_bzero.c \
				ft_strdel.c \
				ft_memalloc.c \
				ft_strcpy.c \
				ft_strnew.c \
				ft_strdup.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_putchar.c \
				ft_putchar_fd.c

PT_SRC	=		ft_printf.c \
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
					ft_put_percent.c \
					zero_check.c \
					wchar_len.c \
					ptr_len.c \
					ft_put_wchar.c \
					ft_put_wstr.c

.PHONY: clean fclean all re cc

LIB_SRCS =	$(addprefix $(L_PATH)/, $(LIB_SRC))
PT_SRCS =	$(addprefix $(S_PATH)/, $(PT_SRC))

LIB_OBJ	=	$(LIB_SRCS:.c=.o)
PT_OBJ =	$(PT_SRCS:.c=.o)

all: $(NAME)

$(LIB_OBJ): %.o: %.c
		@$(CC) -c $(FLAGS) $< -o $@

$(PT_OBJ): %.o: %.c
		@$(CC) -c $(FLAGS) $< -o $@ 		

$(NAME): $(LIB_OBJ) $(PT_OBJ)
		@ar rc $(NAME) $(LIB_OBJ) $(PT_OBJ)
		@ranlib $(NAME)
		@echo "Printf Library Created!"

clean:
	@rm -rf $(LIB_OBJ) $(PT_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: fclean all clean

cc: $(CC) $(FLAGS) -L. $(NAME) main.c

nm: norminette -R CheckForbiddenSourceHeader

