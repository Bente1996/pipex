/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:21:04 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/12 14:41:06 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(char *file, int oflag)
{
	if (oflag == READ)
		file = open(file, O_RDONLY); //read file that is first parameter
	else
		file = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644); // write in file that is last parameter
	if (file < 0 && oflag == READ)
		exit_with_failure("Opening file1 failed\n", 1, 1);
	else if (file < 0)
		exit_with_failure("Opening file2 failed\n", 1, 1);
	return (file);
}

void	ft_close(int file, int flag)
{
	if (close(file) == -1)
	{
		if (flag == 1)
			exit_with_failure("Closing file1 failed\n", 1, 1);
		else if (flag == 2)
			exit_with_failure("Closing file2 failed\n", 1, 1);
		else if (flag == 3)
			exit_with_failure("Closing pipe[READ] failed\n", 1, 1);
		else if (flag == 3)
			exit_with_failre("Closing pipe[WRITE] failed\n", 1, 1);
	}
}
