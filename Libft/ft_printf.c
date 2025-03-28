/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:02:21 by bde-koni          #+#    #+#             */
/*   Updated: 2025/02/04 16:55:36 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *print, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	va_start(args, print);
	i = 0;
	count = 0;
	while (print[i] != '\0')
	{
		if ((print[i] == '%') && (print[i + 1] != '\0'))
		{
			i++;
			count += handle_print(print[i], args);
		}
		else
			count += write(1, &print[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

size_t	handle_print(char is_flag, va_list args)
{
	if (is_flag == 'c')
		return (handle_char(va_arg(args, int)));
	else if (is_flag == 's')
		return (handle_string(va_arg(args, char *)));
	else if (is_flag == 'p')
		return (handle_pointer(va_arg(args, void *)));
	else if ((is_flag == 'd') || (is_flag == 'i'))
		return (handle_signed(va_arg(args, int)));
	else if (is_flag == 'u')
		return (handle_unsigned(va_arg(args, unsigned int)));
	else if (is_flag == 'x')
		return (handle_hexa_low(va_arg(args, unsigned int)));
	else if (is_flag == 'X')
		return (handle_hexa_up(va_arg(args, unsigned int)));
	else if (is_flag == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

size_t	ft_hexalen(uintptr_t x)
{
	size_t	len;

	len = 0;
	while (x > 0)
	{
		x /= 16;
		len++;
	}
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
