/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:01:15 by mumontei          #+#    #+#             */
/*   Updated: 2022/11/28 17:11:48 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char **get_path(char **envp)
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