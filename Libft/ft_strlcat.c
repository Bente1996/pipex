/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:16:34 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:15:40 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION:copy and concatenate
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			dstlen;
	size_t			srclen;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	dstlen = i;
	while (src[j] != '\0')
		j++;
	srclen = j;
	j = 0;
	if (dstlen >= size)
		return (size + srclen);
	while ((src[j] != '\0') && (size > 1 + dstlen))
	{
		dst[i] = src[j];
		j++;
		i++;
		size--;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}

// int main(void)
// {
//     char dst[55] = "KOOPOOPOOP";
//     char src[55] = "3333333333333";
//
//     printf("%ld \n", ft_strlcat(dst, src, 15));
//     printf("%s \n", dst);
//     return (0);
// }