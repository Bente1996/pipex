/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:35:49 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/12 17:07:43 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**safe_split(char *str, char delimeter, int flag)
{
	char	**split;
	
	split = ft_split(str, delimeter);
	if (split == NULL)
	{
		if (flag == 0)
			exit_with_failure("Split cmd_args failed\n", 1, 1);
		else if (flag == 1)
			exit_with_failure("Split paths failed\n", 1, 1);
	}
	return (split);
}

void	free_split(char **paths) // free splitted (OG) paths
{
	int	i;

	i = 0;
	while (paths[i] != NULL)
	{
		free(paths[i]);
		i++;
	}
	free(paths); // free pointer to paths
}

void	free_strings(char **strings, char *string, int flag)
{
	if (flag == 1)
	{
		free_split(strings);
		exit_with_failure("Strjoin slash failed\n", 1, 1);
	}
	else if (flag == 2)
	{
		free(string);
		free_split(strings);
		exit_with_failure("Strjoin cmd failed\n", 1, 1);
	}
	else if (flag == 3)
	{
		free_split(strings);
		exit_with_failure("Command not found\n", 0, 127);
	}
	else if (flag == 4)
	{
		free(string);
		free_split(strings);
		exit_with_failure("Execve failed\n", 1, 1);
	}
}
