#include "ft_printf.h"

static int	ft_dispatch(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), 1));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		i;

	va_start(ap, format);
	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ret += ft_dispatch(ap, format[i + 1]);
			i += 2;
		}
		else
		{
			ret += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (ret);
}
