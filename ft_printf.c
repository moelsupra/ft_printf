#include "ft_printf.h"


int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[count] != '\0')
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}

int	handle_specifier(char specifier, va_list args)
{
	if (specifier == '\0')
		return (0);
	else if (specifier == 'c')
		return (print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (print_str(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_number(va_arg(args, int)));
	else if (specifier == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (print_hex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (print_hex(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
	{
		write(1, "%", 1);
		write(1, &specifier, 1);
		return (2);
	}
}

int	ft_printf(const char *str, ...)
{
	int	count;
	int	i;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break;
			count += handle_specifier(str[i], args);
		} 
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}


