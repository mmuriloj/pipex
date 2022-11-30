#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>


# define RED			"\033[31m"
# define RESET_COLOR	"\e[m"

void	check_args(int argc);
char	**get_path_directories(char **envp);
void	execute_command(char *argv, char **envp);
char	*command_path(char *cmd, char **envp);
void	error_msg(char *msg);
#endif