/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:01:15 by mumontei          #+#    #+#             */
/*   Updated: 2022/11/29 14:55:37 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char **get_path_directory(char **envp)
{
	size_t	line;
	char *path;
	
	line = -1;
	while(envp[++line])
	{
		if (!(ft_strncmp("PATH=", envp[line], 5)))
			path = envp[line];
	}
	return (ft_split(path, ':'));
}

/*
void execute_command(char *cmd, char **envp)
{
	env_path(envp);
}*/

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*temp;
	int		i;

	paths = get_path_directory(envp);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute_command(char *argv, char **envp)
{
	char	**cmd;
	int 	i;
	char	*path;
	
	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)	
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error_msg("");
	}
	if (execve(path, cmd, envp) == -1)
		error_msg("");
}