/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:40:44 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/11 22:53:29 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include "Libft/ft_printf.h"
# include "Libft/get_next_line.h"

typedef struct s_node
{
	char    *file1;
    char    *cmd1;
    char    *cmd2;
    char    *file2;
}	t_node;

void	pipex(t_node *arguments, char **envp);
char	*find_path_line(char **envp);
void	change_program(char *cmd, char **envp);

#endif
