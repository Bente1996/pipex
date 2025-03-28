/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:01:37 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/29 16:22:00 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handle_pointer(void *p)
{
	size_t	count;

	count = 0;
	if (p == NULL)
	{
		ft_putstr("(nil)");
		count += 5;
	}
	else
	{
		ft_putaddress(p);
		count += 2;
		count += ft_hexalen((uintptr_t)p);
	}
	return (count);
}

void	ft_puthexa_ptr(uintptr_t x)
{
	if (x >= 16)
		ft_puthexa_ptr(x / 16);
	ft_putchar("0123456789abcdef"[x % 16]);
}

void	ft_putaddress(void *p)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)p;
	ft_putstr("0x");
	ft_puthexa_ptr(ptr);
}
