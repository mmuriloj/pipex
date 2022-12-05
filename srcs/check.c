/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:13:33 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/05 17:17:04 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_args(int argc, t_pipex *ppx)
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
	ppx->exit = 0;
}
