/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:21:53 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/19 15:31:41 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
	{
		c -= 32;
	}
	return (c);
}

// int main(void)
// {
//     int c = 'F';
//
//     printf("%c \n", ft_toupper(c));
//     return (0);
// }