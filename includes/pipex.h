#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex
{
	int	pid_in;
	int	pid_out;
	int	fd[2];
}	t_pipex;

#endif