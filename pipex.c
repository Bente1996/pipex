/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:40:54 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/07 17:26:41 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	pipex(char *file1, char *cmd1, char *cmd2, char *file2, char **envp) // parent process, ** ipv *?
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
		dup2(fd1, STDIN_FILENO); // stdin wijst naar file1 (oldfd, newfd)  NIEUW WIJST NAR OUD
		//printf("%d\n", fd1); // = -1 nu
		dup2(pipefd[1], STDOUT_FILENO); // stdout wijst naar write end van pipe
		close(pipefd[0]); // close unsused read end
		change_program(cmd1, envp); //geef command mee en voer uit op juiste file met execve
	}
	else // doe dit in de parent process (cmd 2 and read from pipe)
	{
		dup2(pipefd[0], STDIN_FILENO); // (read end / read from fd[0] is now stdin)
		dup2(fd2, STDOUT_FILENO); // stdout is nu fd2
		close(pipefd[1]); // close unused write end
		change_program(cmd2, envp);
	}
}

char	*find_path_line(char **envp) // opzoek naar PATH= in envp
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

void	free_split(char **paths)
{
	int	i;

	i = 0;
	while (paths[i] != NULL)
	{
		free(paths[i]);
		i++;
	}
}

char	*find_path(char **paths, char *cmd) // vind volledige path
{
	int	i;
	char	*full_path;
	char	*add_slash;

	i = 0;
	full_path = NULL;
	add_slash = NULL;
	while (paths[i] != NULL) // maak volledige paths
	{
		add_slash = ft_strjoin(paths[i], "/"); // we maken een 3e string /bin + "/" = /bin/
		full_path = ft_strjoin(add_slash, cmd); // we maken een 4e string /bin/cat
		free(add_slash); // verwijder 3e string
		if (access(full_path ,X_OK) == 0) // als we gevonden: geef execute recht
		{
			free_split(paths); // free alle OG paths, "/" hoeft niet
			return (full_path);
		}
		i++;
		free(full_path); // deze werkte niet, free 4e string
	}
	free_split(paths); // niet gevonden, free alle OG paths
	return (NULL); // niet gevonden
}

void	change_program(char *cmd, char **envp) // "cat -e"
{
	char	*path_line;
	char	**cmd_args;
	char	**paths;
	char	*full_path;
	
	cmd_args = ft_split(cmd, ' '); // breek command in stukken
	path_line = find_path_line(envp); // zoek naar PATH in envp
	paths = ft_split(path_line, ':'); // split bij :
	full_path = find_path(paths, cmd_args[0]);
	execve(path_line, cmd_args, envp);	
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	return (1);

	pipex(argv[1], argv[2], argv[3], argv[4], envp);
	return(0);
}
