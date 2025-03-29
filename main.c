/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:40:54 by bde-koni          #+#    #+#             */
/*   Updated: 2025/03/29 19:08:25 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_pipe(char *file1, char *cmd1, char *cmd2, char *file2)
{
	int	fd[2]; // twee fd's: stdin en stdout
	pid_t	pid1;
	pid_t	pid2;
	int	input_file;
	int	output_file;
	
	input_file = open(file1, O_RDONLY); //read file that is first parameter
	output_file = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644); // create file that is last parameter

	pipe(fd);
	pid1 = fork();

	if (pid1 == 0) // doe dit in de child process (cmd 1)
	{
		dup2(input_file, STDIN_FILENO); // read from input file
		dup2(fd[1], STDOUT_FILENO); // (write end / write to fd[1] / stdout)
		close(fd[0]); // close unsused read end

		execve(cmd1[0], cmd1, NULL); // switch to new program (pathname, parameters, envp)
	}
	else // doe dit in de parent process (cmd 2)
	{
		pid2 = fork();
		
		if (pid2 == 0) // maak nieuwe child, waarom?
		{
			dup2(fd[0], STDIN_FILENO); // (read end / read from fd[0] / stdin)
			dup2(output_file, STDOUT_FILENO); // write to output file
			close(fd[1]); // close unused write end
			
			execve(cmd1[0], cmd1, NULL);
		}
		else
		{
			close(fd[0]);
			close(fd[1]);
			close(input_file);
			close(output_file);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
	
}

void	ft_fork()
{
	int child_pid;

	child_pid = 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		printf("hoi ik ben een child process");
	}
	else
		printf("hoi ik ben een parent process");
	printf("%d\n", child_pid);
}

int	main(int argc, char **argv)
{
	if (argc != 5)
		return (1);

	ft_pipe(argv[1], argv[2], argv[3], argv[4]);
	return(0);
}
