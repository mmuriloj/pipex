/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:22:51 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/04 08:32:25 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int		len;

	len = ft_strlen(s);
	sdup = malloc(1 + len * sizeof(char));
	if (!sdup)
		return (sdup);
	ft_memcpy(sdup, s, len);
	sdup[len] = '\0';
	return ((char *)sdup);
}
