/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:02:17 by troberts          #+#    #+#             */
/*   Updated: 2022/07/11 15:17:19 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_args(va_list args, const char *fmt)
{
	if (fmt[0] == '%')
		return (write(1, "%", 1));
	else if (fmt[0] == 'i' || fmt[0] == 'd')
		return (_ft_printf_print_int(args));
	else if (fmt[0] == 'c')
		return (_ft_printf_print_char(args));
	else if (fmt[0] == 's')
		return (_ft_printf_print_str(args));
	else if (fmt[0] == 'u')
		return (_ft_printf_print_unsigned(args));
	else if (fmt[0] == 'x')
		return (_ft_printf_print_lower_hex(args));
	else if (fmt[0] == 'X')
		return (_ft_printf_print_upper_hex(args));
	else if (fmt[0] == 'p')
		return (_ft_printf_print_ptr(args));
	else
		return (PRINTF_ERROR_CODE);
}

static int	scan_args(va_list args, const char *fmt)
{
	int	i;
	int	nbr_print;
	int	tmp;

	i = 0;
	nbr_print = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] != '\0')
			{
				tmp = process_args(args, fmt + i);
				if (tmp == PRINTF_ERROR_CODE)
					return (PRINTF_ERROR_CODE);
				nbr_print += tmp;
			}
		}
		else
			nbr_print += write(1, &fmt[i], 1);
		i++;
	}
	return (nbr_print);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		nbr_print;

	va_start(args, fmt);
	nbr_print = scan_args(args, fmt);
	va_end(args);
	if (nbr_print == PRINTF_ERROR_CODE)
		return (PRINTF_ERROR_CODE);
	return (nbr_print);
}
