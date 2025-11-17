/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelamma <moelamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:36:50 by moelamma          #+#    #+#             */
/*   Updated: 2025/11/17 22:41:51 by moelamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int n)
{
	int		count;
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
	int		count;
	char	c;

	count = 0;
	if (n > 9)
		count += print_unsigned(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
