/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:03:56 by mumontei          #+#    #+#             */
/*   Updated: 2022/05/10 03:24:15 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_func;
	size_t	i;

	str_func = NULL;
	if (!s)
		return (str_func);
	str_func = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str_func)
		return (str_func);
	i = 0;
	while (s[i] != '\0')
	{
		str_func[i] = f(i, s[i]);
		i++;
	}
	str_func[i] = '\0';
	return (str_func);
}
