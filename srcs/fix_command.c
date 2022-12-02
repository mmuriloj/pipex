/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:30:10 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/02 10:59:00 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/pipex.h"

void	cut_value(char ***cmd_arg)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*cmd_arg)[i])
	{
		if (((*cmd_arg)[i][0] == '\'') || ((*cmd_arg)[i][0] == '\"'))
		{
			temp = ft_substr((*cmd_arg)[i], 1, ft_strlen((*cmd_arg)[i]) - 2);
			free ((*cmd_arg)[i]);
			(*cmd_arg)[i] = temp;
		}
		i++;
	}
}

void	turn_back(char ***cmd_arg)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while ((*cmd_arg)[i])
	{
		while ((*cmd_arg)[i][i2])
		{
			if (((*cmd_arg)[i][i2] == '\'') || ((*cmd_arg)[i][i2] == '\"'))
			{
				i2++;
				while (((*cmd_arg)[i][i2] != '\'') \
				&& ((*cmd_arg)[i][i2] != '\"') && ((*cmd_arg)[i][i2]))
				{
					if ((*cmd_arg)[i][i2] == 1)
						(*cmd_arg)[i][i2] = ' ';
					i2++;
				}
			}
			i2++;
		}
		i++;
		i2 = 0;
	}
}

void	swap_value(char **cmd, t_pipex *ppx)
{
	int		i;

	i = 0;
	while ((*cmd)[i])
	{
		if (((*cmd)[i] == '\'') || ((*cmd)[i] == '\"'))
		{
			i++;
			if (!(*cmd)[i])
				quotes_error();
			ppx->check = 1;
			while ((((*cmd)[i] != '\'') && ((*cmd)[i] != '\"')) && (*cmd)[i])
			{
				if ((*cmd)[i] == ' ')
					(*cmd)[i] = 1;
				i++;
				if (!(*cmd)[i])
					quotes_error();
			}
		}
		i++;
	}
}

char	**pipex_cmd_arg(char *cmd, t_pipex *ppx)
{
	char	**cmd_arg;

	cmd_arg = NULL;
	ppx->check = 0;
	swap_value(&cmd, ppx);
	cmd_arg = ft_split(cmd, ' ');
	if (ppx->check == 1)
	{
		ppx->check = 0;
		turn_back(&cmd_arg);
		cut_value(&cmd_arg);
	}
	return (cmd_arg);
}

