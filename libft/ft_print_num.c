/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:32:42 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/05 17:18:23 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	n_digits(int nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
		count++;
	while (nbr)
	{
		nbr = (nbr / 10);
		count++;
	}
	return (count);
}

int	ft_print_int(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = (int)(nb * -1);
	}
	else
		nbr = (int)nb;
	if (nbr >= 10)
		ft_print_int(nbr / 10);
	ft_putchar_fd((char)(nbr % 10 + 48), 1);
	return (n_digits(nb));
}

int	ft_print_u(unsigned int num)
{
	int	i;

	i = 0;
	if (num > 9)
		i += ft_print_u(num / 10);
	write(1, &"0123456789"[num % 10], 1);
	i++;
	return (i);
}
