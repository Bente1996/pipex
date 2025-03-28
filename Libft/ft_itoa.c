/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:39:31 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/26 15:17:25 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lencheck(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// FUNCTION: integer to characters
char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	long	n2;

	if (n == 0)
		return (ft_strdup("0"));
	n2 = (long)n;
	len = ft_lencheck(n2);
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	if (n2 < 0)
	{
		s[0] = '-';
		n2 *= -1;
	}
	s[len] = '\0';
	while (n2 > 0)
	{
		len--;
		s[len] = (n2 % 10) + 48;
		n2 /= 10;
	}
	return (s);
}

// int main(void)
// {
//     int n = -2147483648;
//     printf("%s \n", ft_itoa(n));
//     return(0);
// }