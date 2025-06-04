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
	dup2(fd1, STDIN_FILENO); // stdin wijst naar file1 (oldfd, newfd)  NIEUW WIJST NAR OUD
	//printf("%d\n", fd1); // = -1 nu
	dup2(pipefd[WRITE], STDOUT_FILENO); // stdout wijst naar write end van pipe
	ft_close(fd1, 1); // already duped
	ft_close(pipefd[READ], 3); // close unsused read end
	change_program(cmd1, envp); //geef command mee en voer uit op juiste file met execve
}

void	child_2(int *pipefd, int fd2, char *cmd2, char **envp)
{
	dup2(pipefd[READ], STDIN_FILENO); // (read end / read from fd[0] is now stdin)
	dup2(fd2, STDOUT_FILENO); // stdout is nu fd2
	ft_close(fd2, 2); // already duped
	ft_close(pipefd[WRITE], 4); // close unused write end
	change_program(cmd2, envp);
}

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

void	change_program(char *cmd, char **envp) // "cat -e"
{
	char	*path_line;
	char	**cmd_args;
	char	**paths;
	char	*full_path;
	
	cmd_args = safe_split(cmd, ' ', 0); // breek command in stukken
	if (ft_strchr(cmd_args[0], '/') != NULL) // als het absolute path al gegeven is: strdup
		full_path = ft_strdup(cmd_args[0]);
	else
	{
		path_line = find_path_line(envp); // zoek naar PATH in envp
		paths = safe_split(path_line, ':', 1); // split bij :
		full_path = find_path(paths, cmd_args[0]);
	}
	if (full_path == NULL)
		free_strings(cmd_args, full_path, 3);
	if (execve(full_path, cmd_args, envp) == -1) // niet nodig on succeed want dan wordt alles gewiped door nieuwe programma
		free_strings(cmd_args, full_path, 4);
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

char	*build_path(char **paths, char* current_path, char *cmd)
{
	char	*add_slash;
	char	*full_path;

	full_path = NULL;
	add_slash = ft_strjoin(current_path, "/"); // we maken een 3e string /bin + "/" = /bin/
	if (add_slash == NULL)
		free_strings(paths, full_path, 1);
	full_path = ft_strjoin(add_slash, cmd); // we maken een 4e string /bin/cat
	if (full_path == NULL)
		free_strings(paths, full_path, 2);
	free(add_slash); // verwijder 3e string
	return(full_path);
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
		full_path = build_path(paths, paths[i], cmd);
		if (access(full_path ,X_OK) == 0) // als gevonden: geef execute recht, F_OK????????
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

char	**safe_split(char *str, char delimeter, int flag)
{
	char	**split;
	
	split = ft_split(str, delimeter);
	if (split == NULL)
	{
		if (flag == 0)
			exit_with_failure("Split cmd_args failed\n", 1, 1);
		else if (flag == 1)
			exit_with_failure("Split paths failed\n", 1, 1);
	}
	return (split);
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

void	free_strings(char **strings, char *string, int flag)
{
	if (flag == 1)
	{
		free_split(strings);
		exit_with_failure("Strjoin slash failed\n", 1, 1);
	}
	else if (flag == 2)
	{
		free(string);
		free_split(strings);
		exit_with_failure("Strjoin cmd failed\n", 1, 1);
	}
	else if (flag == 3)
	{
		free_split(strings);
		exit_with_failure("Command not found\n", 0, 127);
	}
	else if (flag == 4)
	{
		free(string);
		free_split(strings);
		exit_with_failure("Execve failed\n", 1, 1);
	}
}

pid_t	ft_fork()
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_with_failure("Forking went wrong\n", 1, 1);
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

ft_dup2()
{
	
}

void	exit_with_failure(char *message, int use_perror, int error_code)
{
	if (use_perror)
		perror(message);
	else
		ft_putendl_fd(message, 2); // write to stderr
	exit(error_code);
}

int	main(int argc, char **argv, char **envp)
{
	t_node	arguments;

	if (argc != 5)
		exit_with_failure("Invalid amount of arguments\n", 0, 2);
	arguments.file1 = argv[1];
	arguments.cmd1 = argv[2];
	arguments.cmd2 = argv[3];
	arguments.file2 = argv[4];
	pipex(&arguments, envp);
	return(0);
}