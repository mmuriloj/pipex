/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:28:17 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/05 17:16:40 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_msg(char *msg, t_pipex *ppx)
{
	reset_stdout(ppx);
	ft_printf("pipex: ");
	perror(msg);
	exit(EXIT_FAILURE);
}

void	quotes_error(void)
{
	ft_printf("Error\nBad input in single quotes (\') or double quotes (\").\n");
	exit(EXIT_FAILURE);
}

void	reset_stdout(t_pipex *ppx)
{
	dup2(ppx->saved_stdout, 1);
	close(ppx->saved_stdout);
}

void	function_failure(char *func_name, t_pipex *ppx)
{
	reset_stdout(ppx);
	ft_printf("pipex: %s", func_name);
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char **cmd, t_pipex *ppx)
{
	int	i;

	reset_stdout(ppx);
	ft_printf("pipex: %s: command not found\n", cmd[0]);
	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
	exit(COMMAND_NOT_FOUND);
}
