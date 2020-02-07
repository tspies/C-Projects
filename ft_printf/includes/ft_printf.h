/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 08:17:19 by tspies            #+#    #+#             */
/*   Updated: 2018/08/19 08:17:22 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIERS "%sSdDoOuUxXcCip"
# define FULL_LIST "sSdDoOuUxXcCip+-#0 .123456789hljz"
# define CHECK_LIST "+-#0 .123456789hljz"
# define FLAGS "+-#0 "
# define LEN_MOD "lhjz"
# define OCT_LIST "01234567"
# define ABS(x) ((x < 0) ? -(x) : (x))

/*
** ----------Librarys-----------------
*/

# include <stdlib.h>
# include <stdarg.h>
# include <ctype.h>
# include <unistd.h>
# include <wchar.h>

/*
** ----------Structure----------------
*/

typedef struct	s_print{

	short		precision;
	short		f_width;
	char		*flag_list;
	char		specifier;
	short		size;
	char		l;
	char		ll;
	char		h;
	char		hh;
	char		z;
	char		j;
}				t_print;

/*
** ----------Printf Functions---------
*/

int				ft_printf(char *fmt, ...);
int				parse_switchboard(char **fmt, va_list arg);
int				specifier_switchboard(t_print *tab, va_list arg);
int				unsigned_len(t_print *tab, uintmax_t num, uintmax_t base);
int				signed_len(t_print *tab, intmax_t num, intmax_t base);
int				handle_c(t_print *tab, void *c);
int				handle_d(t_print *tab, void *num, intmax_t base);
int				handle_u(t_print *tab, void *num, uintmax_t base);
int				handle_s(t_print *tab, void *str);
int				handle_o(t_print *tab, void *num, uintmax_t base);
int				handle_x(t_print *tab, void *num, uintmax_t base);
int				handle_p(t_print *tab, void *ptr, intmax_t base);
int				ft_put_percent(t_print *tab, char c);
char			wchar_len(unsigned int nbr);
int				ptr_len(t_print *tab, intmax_t num, intmax_t base);
char			ft_put_wchar(wchar_t wchar);
int				ft_put_wstr(wchar_t *wstr, int prec);
void			zero_check(t_print *tab);

/*
** ----------Libft Functions---------
*/

int				ft_strlen(const char *s);
char			ft_strchr(char *s, int c);
int				ft_putstr(char *s, int precision);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
void			ft_strdel(char **as);
void			*ft_memalloc(size_t size);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strnew(size_t size);
char			*ft_strdup(const char *s1);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(char **str);
int				ft_putchar(int c);
int				ft_putchar_fd(int c, int f);
#endif
