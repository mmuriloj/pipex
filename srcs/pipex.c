/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:10:53 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/01 18:27:08 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void child(char **argv, char **envp, t_pipex *ppx)
{
	ppx->fdin = open(argv[1], O_RDONLY);
	if (ppx->fdin == -1)
		error_msg(argv[1]);
	dup2(ppx->fdin, STDIN_FILENO);
	dup2(ppx->pipe_fd[1], STDOUT_FILENO);
	close(ppx->fdin);
	execute_command(argv[2], envp, ppx);
}

void	parent(char **argv, char **envp, t_pipex *ppx)
{
	ppx->fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ppx->fdout == -1)
		error_msg(argv[4]);
	dup2(ppx->pipe_fd[0], STDIN_FILENO);
	dup2(ppx->fdout, STDOUT_FILENO);
	close(ppx->pipe_fd[1]);
	execute_command(argv[3], envp, ppx);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex ppx;
	
	check_args(argc, &ppx);
	if (pipe(ppx.pipe_fd) == -1)
		error_msg("");
	ppx.pid = fork();
	if (ppx.pid == 0)
		child(argv, envp, &ppx);
	waitpid(ppx.pid, NULL, 0);
	parent(argv, envp, &ppx);
	return(ppx.exit);
}