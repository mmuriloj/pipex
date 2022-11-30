/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:09:07 by mumontei          #+#    #+#             */
/*   Updated: 2022/11/29 18:10:16 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

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
