/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:21:04 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/12 17:25:51 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_open(char *file, int oflag)
{
	int	fd;

	if (oflag == READ)
		fd = open(file, O_RDONLY); //read fd that is first parameter
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644); // write in fd that is last parameter
	if (fd < 0 && oflag == READ)
		exit_with_failure("Opening fd1 failed\n", 1, 1);
	else if (fd < 0)
		exit_with_failure("Opening fd2 failed\n", 1, 1);
	return (fd);
}

void	ft_close(int fd, int flag)
{
	if (close(fd) == -1)
	{
		if (flag == 1)
			exit_with_failure("Closing fd1 failed\n", 1, 1);
		else if (flag == 2)
			exit_with_failure("Closing fd2 failed\n", 1, 1);
		else if (flag == 3)
			exit_with_failure("Closing pipe[READ] failed\n", 1, 1);
		else if (flag == 3)
			exit_with_failure("Closing pipe[WRITE] failed\n", 1, 1);
	}
}
