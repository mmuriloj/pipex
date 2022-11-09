/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:42:52 by mumontei          #+#    #+#             */
/*   Updated: 2022/05/15 00:04:38 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	len;
	size_t	j;

	len = ft_strlen(s);
	j = 0;
	if (!s || !f)
		return ;
	while (j < len)
	{
		f(j, s);
		j++;
		s++;
	}
}
