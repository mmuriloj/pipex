#ifndef PIPEX_H
# define PIPEX_H
# define TRUE 1
# define FALSE 0

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
	int		check;
	int		fdin;
	int		fdout;
	char	**paths;
}	t_pipex;

void	check_args(int argc, t_pipex *ppx);
char	**get_path_directories(char **envp);
void	execute_command(char *argv, char **envp, t_pipex *ppx);
char	*command_path(char *cmd, char **envp, t_pipex *ppx);
void	error_msg(char *msg);


#endif