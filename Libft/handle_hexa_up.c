/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:17:36 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/29 16:26:15 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handle_hexa_up(unsigned int xx)
{
	size_t	count;

	count = 0;
	ft_puthexa_up(xx);
	if (xx == 0)
		count += 1;
	else
		count += ft_hexalen(xx);
	return (count);
}

void	ft_puthexa_up(unsigned int xx)
{
	if (xx >= 16)
		ft_puthexa_up(xx / 16);
	ft_putchar("0123456789ABCDEF"[xx % 16]);
}
