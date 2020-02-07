#include "ft_printf.h"

int		ft_put_wstr(wchar_t *wstr, int prec)
{
	int		res;

	res = 0;
	if (wstr == NULL)
		return (ft_putstr("(null)", prec));
	while (*wstr != '\0')
	{
		res += ft_put_wchar(*wstr);
		wstr++;
	}
	return (res);
}