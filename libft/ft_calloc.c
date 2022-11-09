/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:04:26 by mumontei          #+#    #+#             */
/*   Updated: 2022/05/14 23:42:20 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size)
{
	void					*arr;
	long long unsigned int	result;

	arr = NULL;
	result = n_elem * size;
	if (n_elem != 0 && result / n_elem != size)
		return (arr);
	arr = malloc(result);
	if (!arr)
		return (NULL);
	ft_bzero(arr, result);
	return (arr);
}
