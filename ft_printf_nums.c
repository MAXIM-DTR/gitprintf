#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
		ret += ft_putunbr(n / 10);
	ret += ft_putchar('0' + n % 10);
	return (ret);
}

int	ft_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		ret += ft_putchar('-');
		ret += ft_putunbr((unsigned int)(-(long)n));
	}
	else
		ret += ft_putunbr((unsigned int)n);
	return (ret);
}

int	ft_puthex(unsigned long n, int maj)
{
	char	*base;
	int		ret;

	if (maj)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ret = 0;
	if (n >= 16)
		ret += ft_puthex(n / 16, maj);
	ret += ft_putchar(base[n % 16]);
	return (ret);
}
