/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:11:49 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:11:57 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION: NULL terminate values in string for n bytes
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

// int main(void)
// {
//     char str[50] = "Hello World";
//
//     char *ptr = str;
//     ft_bzero(str, 4);
//     printf("%s \n", ptr + 3);
//     return (0);
// }