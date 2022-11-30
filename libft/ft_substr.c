/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 04:11:21 by mumontei          #+#    #+#             */
/*   Updated: 2022/11/29 18:10:30 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size;

	substr = NULL;
	if (!s)
		return (substr);
	size = ft_strlen(s) - start;
	if ((int)size < 0)
		size = 0;
	else if (size > len)
		size = len;
	substr = malloc((size + 1) * sizeof(char));
	if (!substr)
		return (substr);
	i = 0;
	while (start <= ft_strlen(s) && i < size)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
