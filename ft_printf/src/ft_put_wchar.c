#include "ft_printf.h"

char		ft_put_wchar(wchar_t wchar)
{
	char			res;
	char			size;
	unsigned char	byte_index;

	res = 0;
	size = wchar_len(wchar);
	if (size == 1)
		return (ft_putchar(wchar));
	byte_index = (240 << (4 - size)) | (wchar >> ((size - 1) * 6));
	res += ft_putchar(byte_index);
	size--;
	while (size--)
	{
		byte_index = ((wchar >> ((size) * 6)) & 63) | 128;
		res += ft_putchar(byte_index);
	}
	return (res);
}