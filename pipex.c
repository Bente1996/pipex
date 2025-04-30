/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:40:54 by bde-koni          #+#    #+#             */
/*   Updated: 2025/04/30 16:31:55 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	pipex(char *file1, char *cmd1, char *cmd2, char *file2) // parent process, ** ipv *?
{
	int	pipefd[2]; // array of 2 fd's (read(0) and write(1) end)
	pid_t	pid;
	int	fd1; // file1
	int	fd2; //file2
	cmd1 = "cat";
	cmd2 = "";
	cmd2 = cmd1;
	cmd1 = cmd2;
	
	fd1 = open(file1, O_RDONLY); //read file that is first parameter
	fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644); // write in file that is last parameter
	
	pipe(pipefd); // create pipe ([0] and [1]) (pipe is zelfde in beide childs)
	pid = fork(); // make child
	
	if (pid == 0) // doe dit in de child process (cmd 1 and write to pipe)
	{
		dup2(fd1, STDIN_FILENO); // make stdin file1 (oldfd, newfd)
		printf("%d\n", fd1); // = -1 nu
		dup2(pipefd[1], STDOUT_FILENO); // (write end / write to fd[1] is now stdout)
		close(pipefd[0]); // close unsused read end
		change_program(cmd1);
	}
	else // doe dit in de parent process (cmd 2 and read from pipe)
	{
		dup2(pipefd[0], STDIN_FILENO); // (read end / read from fd[0] is now stdin)
		dup2(fd2, STDOUT_FILENO); // stdout is nu fd2
		close(pipefd[1]); // close unused write end
		change_program(cmd2);
	}
}

char	*find_cmd_path(char **cmd_args)
{
	PATH = envp;
	get_next_line(envp); // lees PATH line voor line
}

void	change_program(char *cmd) // "cat -e"
{
	char	*path;
	char	**cmd_args;
	
	cmd_args = ft_split(cmd, ' '); // breek command in stukken
	path = find_cmd_path(cmd_args);
	execve(path, cmd_args, envp);
	
}

int	main(int argc, char **argv)
{
	if (argc != 5)
	return (1);
	pipex(argv[1], argv[2], argv[3], argv[4]);
	return(0);
}
