/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:37:12 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/12 14:37:40 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	ft_fork()
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_with_failure("forking went wrong\n", 1, 1);
	return (pid);
}

void	ft_pipe(int *pipefd)
{
	if (pipe(pipefd) == -1) // create pipe ([0] and [1]) (pipe is zelfde in beide childs)
		exit_with_failure("Pipe failed\n", 1, 1);
}

pid_t	ft_waitpid(pid_t pid, int *status, int options)
{
	pid = waitpid(pid, status, options);
	if (WIFEXITED(*status)) // * want kijken naar de waarde op het adres
		ft_printf("Child exited with this exit code: %d\n", WEXITSTATUS(*status));
	else if (WIFSIGNALED(*status))
		ft_printf("Child was killed by this signal: %d\n", WTERMSIG(*status));
	return (pid);
}