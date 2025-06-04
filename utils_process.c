/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:37:12 by bde-koni          #+#    #+#             */
/*   Updated: 2025/06/04 16:20:25 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_with_failure("Forking went wrong\n", 1, 1);
	return (pid);
}

void	ft_pipe(int *pipefd)
{
	if (pipe(pipefd) == -1)
		exit_with_failure("Pipe failed\n", 1, 1);
}

pid_t	ft_waitpid(pid_t pid, int *status, int options)
{
	pid = waitpid(pid, status, options);
	if (WIFEXITED(*status))
		ft_printf("Child exited with this exit code: %d\n", WEXITSTATUS(*status));
	else if (WIFSIGNALED(*status))
		ft_printf("Child was killed by this signal: %d\n", WTERMSIG(*status)); // weg
	return (pid);
}

void	ft_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		exit_with_failure("Dup2 failed\n", 1, 1);
}