/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:06:26 by mumontei          #+#    #+#             */
/*   Updated: 2022/11/29 18:08:15 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	const char	*char_src;
	char		*char_dest;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	char_src = (const char *)src;
	char_dest = (char *)dest;
	while (i < len)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
