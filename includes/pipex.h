/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:17:30 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/05 23:52:28 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define TRUE 1
# define FALSE 0
# define PIPE_FAILURE "pipe doesn't work.\n"
# define FORK_FAILURE "fork doesn't work.\n"
# define COMMAND_NOT_FOUND 127

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex
{
	pid_t	pid;
	int		pipe_fd[2];
	int		exit;
	int		quote_flag;
	int		fdin;
	int		fdout;
	char	**paths;
	int		saved_stdout;
}	t_pipex;

void	check_args(int argc, t_pipex *ppx);
void	cmd_not_found(char **func_name, t_pipex *ppx);
char	*command_path(char **cmd, char **envp, t_pipex *ppx);
void	error_msg(char *msg, t_pipex *ppx);
void	execute_command(char *argv, char **envp, t_pipex *ppx);
char	**fix_command_arg(char *cmd, t_pipex *ppx);
void	function_failure(char *func_name, t_pipex *ppx);
char	**get_path_directories(char **envp);
void	reset_stdout(t_pipex *ppx);
void	quotes_error(void);

#endif