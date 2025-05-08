/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:40:54 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/08 19:28:14 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

void	exit_with_failure(char *message, int use_perror, int error_code)
{
	if (use_perror)
		perror(message);
	else
		ft_putendl_fd(message, 2); // write to stderr
	exit(error_code);
}

void	pipex(char *file1, char *cmd1, char *cmd2, char *file2, char **envp) // parent process, ** ipv *?
{
	int	pipefd[2]; // array of 2 fd's (read(0) and write(1) end)
	pid_t	pid;
	int	fd1; // file1
	int	fd2; //file2
	
	fd1 = open(file1, O_RDONLY); //read file that is first parameter
	fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644); // write in file that is last parameter
	if (fd1 < 0)
		exit_with_failure("opening file1 failed\n", 1, 1);
	if (fd2 < 0)
		exit_with_failure("opening file2 failed\n", 1, 1);
	if (pipe(pipefd) == -1) // create pipe ([0] and [1]) (pipe is zelfde in beide childs)
		exit_with_failure("pipe failed\n", 1, 1);
	pid = fork(); // make child
	if (pid == 0) // doe dit in de child process (cmd 1 and write to pipe)
	{
		dup2(fd1, STDIN_FILENO); // stdin wijst naar file1 (oldfd, newfd)  NIEUW WIJST NAR OUD
		//printf("%d\n", fd1); // = -1 nu
		dup2(pipefd[1], STDOUT_FILENO); // stdout wijst naar write end van pipe
		close(pipefd[0]); // close unsused read end
		close(pipefd[1]);
		change_program(cmd1, envp); //geef command mee en voer uit op juiste file met execve
	}
	else // doe dit in de parent process (cmd 2 and read from pipe)
	{
		int	status; // integer die status info opslaat met behuld van macro's
		
		dup2(pipefd[0], STDIN_FILENO); // (read end / read from fd[0] is now stdin)
		dup2(fd2, STDOUT_FILENO); // stdout is nu fd2
		close(pipefd[1]); // close unused write end
		close(pipefd[0]);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		ft_printf("Child exited with this exit code: %d\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
		ft_printf("Child was killed by this signal: %d\n", WTERMSIG(status));
		change_program(cmd2, envp);
	}
	close(fd1);
	close(fd2);
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

void	free_split(char **paths) // free splitted (OG) paths
{
	int	i;

	i = 0;
	while (paths[i] != NULL)
	{
		free(paths[i]);
		i++;
	}
	free(paths); // free pointer to paths
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
	if (!cmd_args)
		exit_with_failure("split cmd_args failed\n", 1, 1);
	path_line = find_path_line(envp); // zoek naar PATH in envp
	paths = ft_split(path_line, ':'); // split bij :
	if (!paths)
		exit_with_failure("split paths failed\n", 1, 1);
	full_path = find_path(paths, cmd_args[0]);
	if (!full_path)
	{
		free_split(cmd_args);
		exit_with_failure("command not found\n", 0, 127);
	}
	if (execve(full_path, cmd_args, envp) == -1) // niet nodig on succeed want dan wordt alles gewiped door nieuwe programma
	{
		free(full_path);
		free_split(cmd_args);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		exit_with_failure("invalid amount of arguments\n", 0, 2);
	pipex(argv[1], argv[2], argv[3], argv[4], envp);
	return(0);
}
