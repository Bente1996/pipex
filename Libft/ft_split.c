/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:36:23 by bde-koni          #+#    #+#             */
/*   Updated: 2024/11/20 14:14:44 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_free(char **split, size_t ptr)
{
	size_t	i;

	i = 0;
	while (i < ptr)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**mallocsplit(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = malloc((strcount(s, c) + 1) * sizeof(char *));
	return (split);
}

void	increment(char const *s, char c, unsigned int	*start, size_t	*len)
{
	while (s[*start] == c)
		*start = *start +1;
	while ((s[*start + *len] != c) && (s[*start + *len] != '\0'))
		*len = *len + 1;
}

// FUNCTION: allocates and returns an array of strings
// obtained by splitting s, using the character c
char	**ft_split(char const *s, char c)
{
	unsigned int	start;
	size_t			len;
	size_t			ptr;
	char			**split;

	split = mallocsplit(s, c);
	if (split == NULL)
		return (NULL);
	ptr = 0;
	start = 0;
	while (s[start] != '\0')
	{
		len = 0;
		increment(s, c, &start, &len);
		if (len == 0)
			break ;
		split[ptr] = ft_substr(s, start, len);
		if (split[ptr] == NULL)
			return (ft_free(split, ptr));
		ptr++;
		start = start + len;
	}
	split[ptr] = NULL;
	return (split);
}

// int	main(void)
// {
// 	char const	s[50] = "stringy    thingy swag  fsfsfs sfsfsf ";
// 	size_t	i = 0;
//
// 	char **split = ft_split(s, ' ');
// 	if (split == NULL)
// 		printf("null returned :(\n");
// 	else
// 	{
// 		while (split[i] != NULL)
// 		{
// 			printf("%s \n", split[i]);
// 			i++;
// 		}
// 	}
// 	return(0);
// }