/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:51:41 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:16:40 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION: allocates and returns substring from s
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (((size_t)start >= s_len))
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substr = malloc(len + 1);
	if (substr == NULL)
		return (substr);
	substr[len] = '\0';
	while (len > 0)
	{
		len--;
		substr[len] = s[start + len];
	}
	return (substr);
}

// int main(void)
// {
//     char s[50] = "hallo dit is de hele string hihi haha";
//
//     printf("%s \n", ft_substr(s, 8, 4));
//     return(0);
// }