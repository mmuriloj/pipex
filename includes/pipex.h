#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>


# define RED			"\033[31m"
# define RESET_COLOR	"\e[m"

char	**get_path_directory(char **envp);
void	execute_command(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	error_msg(char *msg);
#endif