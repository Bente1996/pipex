/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:19:28 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/28 19:26:02 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i++;
	return (i);
}

int	has_sign(const char *str)
{
	int	sign;
	int	i;

	sign = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		else
			sign = 1;
	}
	return (sign);
}

long long	convert_to_int(const char *str, int i, long long result, int sign)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result > INT_MAX && ((sign == 0) || (sign == 1))) \
		|| (result * -1 < INT_MIN && (sign == -1)))
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
	return (result);
}

//FUNCTION: characters to integer
int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	result = 0;
	i = skip_spaces(str);
	sign = has_sign(str);
	if (sign)
		i++;
	result = convert_to_int(str, i, result, sign);
	if (sign == -1)
		result *= sign;
	return ((int)result);
}

// int main(void)
// {
//     char nptr[50] = "   +---+4567890";
//
//     printf("%d \n", ft_atoi(nptr));
//     return(0);
// }