/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:30:10 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/06 09:43:04 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	trim_char(char ***cmd_arg)
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

static void	reverse_swap(char ***cmd_arg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*cmd_arg)[i])
	{
		while ((*cmd_arg)[i][j])
		{
			if (((*cmd_arg)[i][j] == '\'') || ((*cmd_arg)[i][j] == '\"'))
			{
				j++;
				while (((*cmd_arg)[i][j] != '\'') \
				&& ((*cmd_arg)[i][j] != '\"') && ((*cmd_arg)[i][j]))
				{
					if ((*cmd_arg)[i][j] == 1)
						(*cmd_arg)[i][j] = ' ';
					j++;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static void	swap_char(char **cmd, t_pipex *ppx)
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
			ppx->quote_flag = TRUE;
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

char	**fix_command_arg(char *cmd, t_pipex *ppx)
{
	char	**cmd_arg;

	cmd_arg = NULL;
	ppx->quote_flag = FALSE;
	swap_char(&cmd, ppx);
	cmd_arg = ft_split(cmd, ' ');
	if (ppx->quote_flag == TRUE)
	{
		ppx->quote_flag = FALSE;
		reverse_swap(&cmd_arg);
		trim_char(&cmd_arg);
	}
	return (cmd_arg);
}
