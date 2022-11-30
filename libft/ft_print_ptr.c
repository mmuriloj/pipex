/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:39:03 by mumontei          #+#    #+#             */
/*   Updated: 2022/11/29 18:08:40 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	print_ptr(void *ptr)
{
	size_t			temp;
	char			*ptr_char;
	size_t			len;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	temp = (size_t)ptr;
	ptr_char = int_to_hex(temp);
	write(1, "0x", 2);
	len = ft_strlen(ptr_char) + 2;
	ft_putstr_fd(ptr_char, 1);
	free(ptr_char);
	return (len);
}

char	*int_to_hex(size_t n)
{
	char				*mem;
	int					i;
	int					digits;
	unsigned long int	ln;

	ln = n;
	digits = num_digits_sixteen(ln);
	i = 0;
	mem = (char *)malloc((digits + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	while (digits)
	{
		mem[digits - 1] = "0123456789abcdef"[ln % 16];
		ln = ln / 16;
		digits--;
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

int	num_digits_sixteen(unsigned long int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		digits++;
		n = n / 16;
	}
	return (digits);
}
