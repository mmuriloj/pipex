/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:09:07 by mumontei          #+#    #+#             */
/*   Updated: 2022/05/10 00:42:05 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		l;
	size_t		b;

	if (!*little)
		return ((char *)big);
	b = 0;
	while (b < len && big[b] != '\0')
	{
		if (big[b] == little[0])
		{
			l = 0;
			while (big[b + l] == little[l] && b + l < len)
			{
				if (little[l + 1] == '\0')
					return ((char *)&big[b]);
				l++;
			}
		}
		b++;
	}
	return (NULL);
}
