/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelamma <moelamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:53:59 by moelamma          #+#    #+#             */
/*   Updated: 2025/11/18 12:56:31 by moelamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_char(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (print_str(va_arg(args, char *)));
	else if (specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (-1);
}

static int	handle_numbers(char specifier, va_list args)
{
	if (specifier == 'd' || specifier == 'i')
		return (print_number(va_arg(args, int)));
	else if (specifier == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (print_hex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (print_hex(va_arg(args, unsigned int), 1));
	else if (specifier == 'p')
		return (print_pointer(va_arg(args, void *)));
	return (-1);
}

int	handle_specifier(char specifier, va_list args)
{
	int	res;

	if (specifier == '\0')
		return (0);
	res = handle_char(specifier, args);
	if (res != -1)
		return (res);
	res = handle_numbers(specifier, args);
	if (res != -1)
		return (res);
	write(1, "%", 1);
	write(1, &specifier, 1);
	return (2);
}
