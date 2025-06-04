/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:40:54 by bde-koni          #+#    #+#             */
/*   Updated: 2025/06/04 16:05:14 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	pipex(t_node *arguments, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		fd1;
	int		fd2;
	int		status[2];

	fd1 = ft_open(arguments->file1, READ);
	fd2 = ft_open(arguments->file2, WRITE);
	ft_pipe(pipefd);
	pid1 = ft_fork();
	if (pid1 == 0)
		child_1(pipefd, fd1, arguments->cmd1, envp);
	pid2 = ft_fork();
	if (pid2 == 0)
		child_2(pipefd, fd2, arguments->cmd2, envp);
	ft_close(fd1, 1);
	ft_close(fd2, 2);
	ft_close(pipefd[WRITE], 4);
	ft_close(pipefd[READ], 3);
	ft_waitpid(pid1, &status[0], 0);
	ft_waitpid(pid2, &status[1], 0);
}

void	child_1(int *pipefd, int fd1, char *cmd1, char **envp)
{
	ft_dup2(fd1, STDIN_FILENO);
	ft_dup2(pipefd[WRITE], STDOUT_FILENO);
	ft_close(fd1, 1);
	ft_close(pipefd[READ], 3);
	change_program(cmd1, envp);
}

void	child_2(int *pipefd, int fd2, char *cmd2, char **envp)
{
	ft_dup2(pipefd[READ], STDIN_FILENO);
	ft_dup2(fd2, STDOUT_FILENO);
	ft_close(fd2, 2);
	ft_close(pipefd[WRITE], 4);
	change_program(cmd2, envp);
}
