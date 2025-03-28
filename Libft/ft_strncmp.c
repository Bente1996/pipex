/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:20:44 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/19 15:26:08 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (n > 1) && (s1[i] != '\0'))
	{
		i++;
		n--;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

// int main(void)
// {
//   char    s1[50] = "baap";
//   char    s2[50] = "baam";
//
//   printf("%d \n", ft_strncmp(s1, s2, 3));
// }
