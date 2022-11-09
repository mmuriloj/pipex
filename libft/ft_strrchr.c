/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:09:13 by mumontei          #+#    #+#             */
/*   Updated: 2022/05/10 00:25:37 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = (char *)s + len;
	while (ptr != s)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
