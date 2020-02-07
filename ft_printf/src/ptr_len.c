#include "ft_printf.h"

static int	signed_size(intmax_t num, intmax_t base)
{
	int		res;

	res = 1;
	num /= base;
	while (num)
	{
		num /= base;
		res++;
	}
	return (res);
}

int			ptr_len(t_print *tab, intmax_t num, intmax_t base)
{
	int		res;
	int		tmp;

	res = signed_size(num, base);
	tmp = 0;
	if (tab->precision != -1 && tab->precision > res)
	{
		tmp = (tab->precision - res);
		res = tab->precision;
	}
	if (tmp > 0)
		tab->precision = tmp;
	if (num != 0)
		res += 2;
	else if (num == 0 && tab->precision == 0)
	{
		tab->precision = -2;
		res = 0;
	}
	else
		tab->precision = -1;
	return (res);
}
