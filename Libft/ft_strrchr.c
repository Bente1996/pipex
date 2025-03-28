/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:20:34 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:16:25 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION: returns pointer to last instance of c in s
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while ((unsigned char)s[len] != '\0')
		len++;
	while (len >= 0)
	{
		if ((unsigned char)s[len] == (unsigned char)c)
		{
			s += len;
			return ((char *)s);
		}
		len--;
	}
	return (NULL);
}

// int main(void)
// {
//     char s[50] = "blablabo&6969&rrrrrr";
//
//     printf("%s \n", ft_strrchr(s, '&'));
//     printf("%p \n", ft_strrchr(s, '&'));
//     return (0);
// }