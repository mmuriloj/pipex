/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:40:22 by mumontei          #+#    #+#             */
/*   Updated: 2022/11/29 18:10:26 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && (ft_strchr(set, s1[i])))
		i++;
	while (len && ft_strchr(set, s1[len]))
		len--;
	if ((int)(len - i + 1) <= 0)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, i, (len - i + 1)));
}
