/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:12:16 by troberts          #+#    #+#             */
/*   Updated: 2022/07/11 13:44:10 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*_ft_printf_get_int(va_list args)
{
	int	integer;

	integer = va_arg(args, int);
	return (ft_itoa(integer));
}

int	_ft_printf_print_int(va_list args)
{
	char	*str;
	int		len;

	str = _ft_printf_get_int(args);
	if (str == NULL)
	{
		write(0, "ERROR MALLOC", 13);
		return (PRINTF_ERROR_CODE);
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
