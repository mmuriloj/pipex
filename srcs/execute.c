/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:01:15 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/05 20:51:35 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path_directories(char **envp)
{
	size_t	line;
	char	*path;

	line = -1;
	while (envp[++line])
	{
		if (!(ft_strncmp("PATH=", envp[line], 5)))
			path = envp[line];
	}
	return (ft_split(path, ':'));
}

char	*command_path(char **cmd, char **envp, t_pipex *ppx)
{
	char	*path;
	char	*temp;
	int		i;

	ppx->paths = get_path_directories(envp);
	i = 0;
	while (ppx->paths[i])
	{
		temp = ft_strjoin(ppx->paths[i], "/");
		path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (ppx->paths[++i])
		free(ppx->paths[i]);
	free(ppx->paths);
	i = -1;
	cmd_not_found(cmd, ppx);
	return (0);
}

void	execute_command(char *argv, char **envp, t_pipex *ppx)
{
	char	**command;
	int		i;
	char	*path;

	i = -1;
	command = fix_command_arg(argv, ppx);
	path = command_path(command, envp, ppx);
	if (!path)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		error_msg("", ppx);
	}
	if (execve(path, command, envp) == -1)
	{
		free(path);
		ft_printf("Error\nexec doesn't work");
	}
}
