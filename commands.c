/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:25:12 by bde-koni          #+#    #+#             */
/*   Updated: 2025/05/15 19:55:01 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	change_program(char *cmd, char **envp) // "cat -e"
{
	char	*path_line;
	char	**cmd_args;
	char	**paths;
	char	*full_path;
	
	if (ft_strchr(cmd, 39) == NULL) // als geen ' 
		cmd_args = safe_split(cmd, ' ', 0); // breek command in stukken
	else
		cmd_args = handle_quotes(cmd);
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

char	**handle_quotes(char *cmd) // "grep 'a    b'"
{
	char	**cmd_args;
	int	i;
	int	j;

	i = 0;
	j = 0;
	cmd_args = malloc(sizeof(char *) * 3); // 3 pointers naar strings: cmd, argument, NULL
	if (cmd_args == NULL)
		return (NULL);
	while (cmd[i] == ' ')
		i++;
	j = i;
	while (cmd[j] && cmd[j] != ' ')
		j++;
	cmd_args[0] = ft_substr(cmd, i, j-i); // make eerste substring "grep"
	if (cmd_args[0] == NULL)
		return (NULL);
	i = j;
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] == 39) // ' gevonden
	{
		i++;
		j = i;
		while (cmd[i] != '\0' && cmd[i] != 39) // zoek tweede substring
			j++;
		if (cmd[j] == '\0') // geen tweede quote gevonden
			return (free(cmd_args[0]), free(cmd_args), NULL); // geen tweede ' gevonden: FOUT EXIT, free dingen
		cmd_args[1] = ft_substr(cmd, i, j-i); // alloceer
		if (cmd_args[1] == NULL)
			return (free(cmd_args[0]), free(cmd_args), NULL);
	}
	else
		cmd_args[1] = NULL; // toch geen quote gevonden ..
	cmd_args[2] = NULL;
	return(cmd_args);
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
