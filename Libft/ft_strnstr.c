/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:17 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:16:18 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION: locates first occurence of little string in big string,
// where not more than len characters are searched
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == '\0' || big == little)
		return ((char *)big);
	while ((big[i] != '\0') && (i < len))
	{
		j = 0;
		while ((big[i + j] != '\0') && ((i + j) < len) \
		&& (big[i + j] == little[j]))
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     const char big[50] = "dit en niet is de grote en niet de kleine string";
//     const char little[50] = "en niet";
//
//     printf("%p \n", ft_strnstr(big, little, 20));
//     printf("%s \n", ft_strnstr(big, little, 20));
//     return(0);
// }