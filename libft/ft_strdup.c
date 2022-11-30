/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:22:51 by mumontei          #+#    #+#             */
/*   Updated: 2022/11/29 18:09:16 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

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
