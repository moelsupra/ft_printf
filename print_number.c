#include "ft_printf.h"

int	print_number(int n)
{
	int	count;
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n *= -1;
	}
	if (n > 9)
		count += print_number(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
	count++;
	return (count);
}

int	print_unsigned(unsigned int n)
{
	int	count;
	char	c;

	count = 0;
	if (n > 9)
		count += print_unsigned(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int print_hex(unsigned long n, int uppercase)
{
	char *base;
	int count;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	
	count = 0;
	if (n >= 16)
		count += print_hex(n / 16, uppercase);
	write(1, &base[n % 16], 1);
	count++;
	return (count);
}