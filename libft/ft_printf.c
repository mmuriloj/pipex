/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:44:13 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/05 17:15:05 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	if (str == 0)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += format_identifier(str, args);
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

int	format_identifier(const char *str, va_list args)
{
	if (*str == '%')
		write(1, "%", 1);
	else if (*str == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (*str == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (*str == 'd' || *str == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_print_u(va_arg(args, unsigned int)));
	else if (*str == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (*str == 'x')
		return (ft_print_hex(va_arg(args, unsigned long int),
				"0123456789abcdef"));
	else if (*str == 'X')
		return (ft_print_hex(va_arg(args, unsigned long int),
				"0123456789ABCDEF"));
	else
		write(1, &str, 1);
	return (1);
}
