/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:20:04 by troberts          #+#    #+#             */
/*   Updated: 2022/07/11 13:43:57 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	_ft_printf_get_char(va_list args)
{
	unsigned char	c;

	c = va_arg(args, int);
	return (c);
}

int	_ft_printf_print_char(va_list args)
{
	char	c;

	c = _ft_printf_get_char(args);
	ft_putchar_fd(c, 1);
	return (LEN_CHAR);
}
