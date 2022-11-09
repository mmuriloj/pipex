/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:18:45 by mumontei          #+#    #+#             */
/*   Updated: 2022/05/15 00:07:26 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	result;

	result = 0;
	sign = 1;
	while (((*str >= '\t' && *str <= '\r') || *str == ' ') && *str != '\0')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1 * sign;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (sign * result);
}
