/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:43:14 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:12:33 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION: cpies n bytes from memory area src to dest
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	const char		*s;
	size_t			i;

	str = dest;
	s = src;
	if (str == NULL && s == NULL)
		return (NULL);
	if ((size_t)(str - (unsigned char *)s) < n)
	{
		i = n - 1;
		while (n > 0)
		{
			str[i] = s[i];
			i--;
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (str);
}

// int main(void)
// {
//     char str[50] = "777771234569999999999";
//     char s[50] = "vlaflip";
//     ft_memmove(&str[5], str ,1);
//
//     printf("%s \n", str);
//     return (0);
// }