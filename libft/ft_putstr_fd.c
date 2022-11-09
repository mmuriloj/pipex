/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 00:51:17 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/26 22:30:53 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
