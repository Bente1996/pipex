/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:40:54 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/12 17:34:50 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_node *arguments, char **envp) // parent process, ** ipv *?
{
	int	pipefd[2]; // array of 2 fd's (read(0) and write(1) end)
	pid_t	pid1;
	pid_t	pid2;
	int	fd1; // file1
	int	fd2; //file2
	int	status[2]; // integer die status info opslaat met behuld van macro's
	
	fd1 = ft_open(arguments->file1, READ);
	fd2 = ft_open(arguments->file2, WRITE);
	ft_pipe(pipefd);
	pid1 = ft_fork(); // make child
	if (pid1 == 0) // doe dit in de child process (cmd 1 and write to pipe)
		child_1(pipefd, fd1, arguments->cmd1, envp);
	pid2 = ft_fork();
	if (pid2 == 0)
		child_2(pipefd, fd2, arguments->cmd2, envp);
	ft_close(fd1, 1);
	ft_close(fd2, 2); 
	ft_close(pipefd[WRITE], 4);
	ft_close(pipefd[READ], 3);
	ft_waitpid(pid1, &status[0], 0); //& omdat je niet nummer maar adres wil meegeven
	ft_waitpid(pid2, &status[1], 0); // doe dit in parent om error codes op te vangen van execve
}

void	child_1(int *pipefd, int fd1, char *cmd1, char **envp)
{
	ft_dup2(fd1, STDIN_FILENO); // stdin wijst naar file1 (oldfd, newfd)  NIEUW WIJST NAR OUD
	//printf("%d\n", fd1); // = -1 nu
	ft_dup2(pipefd[WRITE], STDOUT_FILENO); // stdout wijst naar write end van pipe
	ft_close(fd1, 1); // already duped
	ft_close(pipefd[READ], 3); // close unsused read end
	change_program(cmd1, envp); //geef command mee en voer uit op juiste file met execve
}

void	child_2(int *pipefd, int fd2, char *cmd2, char **envp)
{
	ft_dup2(pipefd[READ], STDIN_FILENO); // (read end / read from fd[0] is now stdin)
	ft_dup2(fd2, STDOUT_FILENO); // stdout is nu fd2
	ft_close(fd2, 2); // already duped
	ft_close(pipefd[WRITE], 4); // close unused write end
	change_program(cmd2, envp);
}
