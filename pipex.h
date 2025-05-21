/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:40:44 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/12 17:12:05 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include "Libft/ft_printf.h"
# include "Libft/get_next_line.h"
# include <errno.h>

#define READ 0
#define WRITE 1

typedef struct s_node
{
	char	*file1;
	char	*cmd1;
	char	*cmd2;
	char	*file2;
}	t_node;

void	pipex(t_node *arguments, char **envp);
void	child_1(int *pipefd, int fd1, char *cmd1, char **envp);
void	child_2(int *pipefd, int fd2, char *cmd2, char **envp);
char	*find_path_line(char **envp);
char	*build_path(char **paths, char* current_path, char *cmd);
char	*find_path(char **paths, char *cmd);
void	change_program(char *cmd, char **envp);
int		ft_open(char *file, int oflag);
void	ft_close(int fd, int flag);
pid_t	ft_fork();
void	ft_pipe(int *pipefd);
void	ft_dup2(int oldfd, int newfd);
pid_t	ft_waitpid(pid_t pid, int *status, int options);
char	**safe_split(char *str, char delimeter, int flag);
void	free_split(char **paths);
void	free_strings(char **strings, char *string, int flag);
void	exit_with_failure(char *message, int use_perror, int error_code);

#endif
