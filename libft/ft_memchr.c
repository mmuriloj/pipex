/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:55:52 by mumontei          #+#    #+#             */
/*   Updated: 2022/04/26 04:06:59 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*elem;

	elem = (char *)s;
	while (n-- > 0)
	{
		if (*elem == (char)c)
			return ((void *)elem);
		elem++;
	}
	return (0);
}
