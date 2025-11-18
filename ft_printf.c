/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelamma <moelamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:36:13 by moelamma          #+#    #+#             */
/*   Updated: 2025/11/18 21:23:58 by moelamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	i = 0;
	count = 0;
	if (!str || write(1, 0, 0) < 0)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[++i] == '\0')
				break ;
			count += handle_specifier(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	return (va_end(args), count);
}
