/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:23:27 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/12 14:45:25 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
