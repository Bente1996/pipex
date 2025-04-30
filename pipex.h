/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:40:44 by bde-koni          #+#    #+#             */
/*   Updated: 2025/04/30 16:46:23 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

void	pipex(char *file1, char *cmd1, char *cmd2, char *file2);
char	*find_cmd_path(char **cmd_args);
void	change_program(char *cmd);
int		main(int argc, char **argv);

#endif
