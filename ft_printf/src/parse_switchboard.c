/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_switchboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:33:55 by tspies            #+#    #+#             */
/*   Updated: 2018/08/16 15:24:10 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		struct_start(t_print *tab)
{
	tab->precision = -1;
	tab->f_width = -1;
	tab->flag_list = ft_strdup(" *****");
	tab->l = 0;
	tab->ll = 0;
	tab->h = 0;
	tab->hh = 0;
	tab->z = 0;
	tab->j = 0;
}

static char		double_checker(char *fmt, char c)
{
	char		result;

	result = 0;
	while (ft_strchr("+-#0 .123456789hljz", *fmt))
	{
		if (*fmt == c)
			result++;
		fmt++;
	}
	if (result % 2 != 0)
		return (1);
	else
		return (0);
}

static void		parse_modifier(char **fmt, t_print *tab)
{
	if (**fmt == 'h' && !(tab->h) && !(tab->hh))
	{
		if (double_checker(*fmt, 'h'))
			tab->h = 1;
		else
			tab->hh = 1;
	}
	if (**fmt == 'l' && !(tab->l) && !(tab->ll))
	{
		if (double_checker(*fmt, 'l'))
			tab->l = 1;
		else
			tab->ll = 1;
	}
	if (**fmt == 'j')
		tab->j = 1;
	if (**fmt == 'z')
		tab->z = 1;
}

static void		parse_flags(char **fmt, t_print *tab)
{
	if (**fmt == '#')
		tab->flag_list[1] = '#';
	else if (**fmt == '0')
		tab->flag_list[2] = '0';
	else if (**fmt == '-')
		tab->flag_list[3] = '-';
	else if (**fmt == '+')
		tab->flag_list[4] = '+';
	else if (**fmt == ' ')
		tab->flag_list[5] = ' ';
}

int				parse_switchboard(char **fmt, va_list arg)
{
	t_print		tab;

	struct_start(&tab);
	while (ft_strchr(CHECK_LIST, **fmt))
	{
		(ft_strchr(FLAGS, **fmt)) ? parse_flags(fmt, &tab) : 0;
		if (ft_strchr("123456789", **fmt))
		{
			tab.f_width = ft_atoi(fmt);
			continue;
		}
		if (**fmt == '.' && (*fmt)++)
		{
			tab.precision = ft_atoi(fmt);
			continue ;
		}
		(ft_strchr(LEN_MOD, **fmt)) ? parse_modifier(fmt, &tab) : 0;
		(*fmt)++;
	}
	if (ft_strchr(SPECIFIERS, **fmt))
		tab.specifier = **fmt;
	else
		tab.specifier = **fmt;
	return (specifier_switchboard(&tab, arg));
}
