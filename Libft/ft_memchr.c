/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:33:29 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:11:26 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION: scans  the  initial n bytes of the memory area
// pointed to by s for the first instance of c
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*str;
	unsigned char			c2;
	unsigned char			*ptr;

	str = s;
	c2 = c;
	i = 0;
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		if (str[i] == c2)
		{
			ptr = (unsigned char *)&str[i];
			return (ptr);
		}
		i++;
		n--;
	}
	return (NULL);
}

// int main(void)
// {
//     char    str[50] = "the first instance of c";
//     printf("%s \n", (char   *)ft_memchr(str, 'i', 2));
//     return(0);
// }
