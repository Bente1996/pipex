/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:12:02 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:15:29 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION: allocates and returns new string,
// which is the result of the concatenation
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s3;
	size_t			i;
	size_t			j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s3 = malloc(i + j + 1);
	if (s3 == NULL)
		return (s3);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

// int	main(void)
// {
// 	char s1[50] = "blablabla";
// 	char s2[50] = "3333333333";
//
// 	printf("%s \n", ft_strjoin(s1, s2));
// 	return(0);
// }