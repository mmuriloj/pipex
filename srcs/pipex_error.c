/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:28:17 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/01 21:29:14 by mumontei         ###   ########.fr       */
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
