/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:59:57 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:15:48 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION: copy src into dest
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	unsigned int	j;

	i = 0;
	j = 0;
	while ((src[i] != '\0'))
	{
		i++;
	}
	if (size == 0)
		return (i);
	while ((src[j] != '\0') && (size > 1))
	{
		dst[j] = src[j];
		j++;
		size--;
	}
	dst[j] = '\0';
	return (i);
}

// int main(void)
// {
//     char    dst[50] = "123456766666666666666666666666666666666666";
//     char    src[50] = "hallo poepje FUNNY GUY HAHAHA";

//     printf("%ld \n", ft_strlcpy(dst, src, 40));
//     printf("%s \n", dst);
//     return (0);
// }