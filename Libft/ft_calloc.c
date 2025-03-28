/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:47:13 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:12:08 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// FUNCTION: allocates memory for an array of nmemb elemts of
// size bytes and returns pointer to allocated memory
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	storage;

	if ((size != 0) && (nmemb > __SIZE_MAX__ / size))
		return (0);
	storage = nmemb * size;
	ptr = malloc(storage);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, storage);
	return (ptr);
}

// int main(void)
// {
//     char str[50] = "naar nul brengen";
//
//     ft_calloc(2, 1);
//     printf("%s", );
//     return(0);
// }