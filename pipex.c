/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:40:54 by bde-koni          #+#    #+#             */
/*   Updated: 2025/04/29 19:02:55 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	pipex(char *file1, char *cmd1, char *cmd2, char *file2) // parent process
{
	int	pipefd[2]; // array of 2 fd's (read(0) and write(1) end)
	pid_t	pid;
	int	fd1; // file1
	int	fd2; //file2
	cmd1 = "";
	cmd2 = "";
	cmd2 = cmd1;
	cmd1 = cmd2;
	
	fd1 = open(file1, O_RDONLY); //read file that is first parameter
	fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644); // write in file that is last parameter
	
	pipe(pipefd); // create pipe ([0] and [1]) (pipe is zelde in beide childs)
	pid = fork(); // make child
	
	if (pid == 0) // doe dit in de child process (cmd 1 and write to pipe)
	{
		dup2(fd1, STDIN_FILENO); // make stdin file1 (oldfd, newfd)
		printf("%d\n", fd1); // = -1 nu
		dup2(pipefd[1], STDOUT_FILENO); // (write end / write to fd[1] is now stdout)
		close(pipefd[0]); // close unsused read end
		//execve(cmd1[0], cmd1, NULL); // switch to new program (pathname, parameters, envp)
	}
	else // doe dit in de parent process (cmd 2 and read from pipe)
	{
		dup2(pipefd[0], STDIN_FILENO); // (read end / read from fd[0] is now stdin)
		dup2(fd2, STDOUT_FILENO); // write to output file
		close(pipefd[1]); // close unused write end
		
		//execve(cmd1[0], cmd1, NULL);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 5)
	return (1);
	pipex(argv[1], argv[2], argv[3], argv[4]);
	return(0);
}
