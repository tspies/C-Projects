#include "ft_printf.h"

int		ft_put_percent(t_print *tab, char c)
{
	int		res;

	res = 0;
	zero_check(tab);
	if ((tab->flag_list)[3] != '-' && tab->f_width > 1)
		while ((tab->f_width)-- -1)
			res += ft_putchar((tab->flag_list)[0]);
	res += ft_putchar(c);
	if ((tab->flag_list)[3] == '-' && tab->f_width > 1)
		while ((tab->f_width)-- -1)
			res += ft_putchar(' ');
	return (res);
}