/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-koni <bde-koni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:41:09 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/12 14:41:31 by bde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_failure(char *message, int use_perror, int error_code)
{
	if (use_perror)
		perror(message);
	else
		ft_putendl_fd(message, 2); // write to stderr
	exit(error_code);
}
