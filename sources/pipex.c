/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:10:53 by mumontei          #+#    #+#             */
/*   Updated: 2022/11/30 11:39:48 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_msg(char *msg)
{
	ft_printf("bash: ");
	perror(msg);
	exit(EXIT_FAILURE);
}

void check_args(int argc)
{
	if (argc != 5)
	{
		if (argc < 5)
			ft_printf("Not enough parameters\n");
		else
			ft_printf("Too many parameters\n");
		ft_printf("Use: ./pipex infile cmd1 cmd2 outfile\n");
		exit(EXIT_FAILURE);
	}
}

void child(char **argv, int fd[2], char **paths)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY, 0777);
	if (file_in == -1)
		error_msg(argv[1]);
	dup2(file_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(file_in);
	execute_command(argv[2], paths);
}

void	parent(char **argv, int *fd, char **paths)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
		error_msg("");
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	execute_command(argv[3], paths);
}

int main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];
	
	check_args(argc);
	if (pipe(pipe_fd) == -1)
		error_msg("");
	pid = fork();
	if (pid == 0)
		child(argv, pipe_fd, envp);
	waitpid(pid, NULL, 0);
	parent(argv, pipe_fd, envp);
}

//int i = -1;
//ft_printf("\n", envp[i]);
//while(envp[++i])
//	ft_printf(">> %s\n", envp[i]);