/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:10:53 by mumontei          #+#    #+#             */
/*   Updated: 2022/11/28 17:15:08 by mumontei         ###   ########.fr       */
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

void child(char *file, int fd[2], char **envp)
{
	int	file_in;

	file_in = open(file, O_RDONLY, 0777);
	if (file_in == -1)
		error_msg(file);
	dup2(file_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(file_in);
	//execute_command()
}

void	parent(char **argv, int *fd, char **envp)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
		error_msg("");
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	//execute_command()
}

int main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];
	char	**path;
	
	check_args(argc);
	path = get_path(envp);
	if (pipe(pipe_fd) == -1)
		error_msg("");
	pid = fork();
	if (pid == 0)
		child(argv[1], pipe_fd, envp);
	waitpid(pid, NULL, 0);
	parent(argv, pipe_fd, envp);
}