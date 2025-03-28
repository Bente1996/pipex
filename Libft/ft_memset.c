/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:39:52 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:12:46 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION: fills first n bytes of memory area
// pointed to by s with constant byte c
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n > 0)
	{
		*str = (unsigned char) c;
		str++;
		n--;
	}
	return (s);
}

// int main(void)
// {
//     char str[50] = "Hello World";
//
// 	ft_memset(str, '#', 9);
//     printf("%s \n", str);
//     return (0);
// }