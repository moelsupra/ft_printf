/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelamma <moelamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:36:46 by moelamma          #+#    #+#             */
/*   Updated: 2025/11/17 23:14:44 by moelamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	handle_specifier(char specifier, va_list args);
int	print_char(int c);
int	print_str(char *s);
int	print_number(int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned long n, int uppercase);
int	print_pointer(void *ptr);

#endif
