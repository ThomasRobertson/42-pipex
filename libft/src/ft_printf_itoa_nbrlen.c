/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_nbrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 00:11:25 by troberts          #+#    #+#             */
/*   Updated: 2022/07/11 13:43:46 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	_ft_printf_u_nbrlen(size_t n, int base_lenght)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base_lenght;
		len++;
	}
	return (len);
}

char	*_ft_printf_ft_uitoa(size_t n, int base_lenght)
{
	char	*str;
	size_t	len;
	size_t	nbr;

	len = _ft_printf_u_nbrlen(n, base_lenght);
	str = malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = 0;
	nbr = n;
	if (nbr == 0)
		str[0] = '0';
	while (len && nbr)
	{
		len--;
		if (base_lenght <= 10 || nbr % base_lenght <= 9)
			str[len] = nbr % base_lenght + '0';
		else
			str[len] = nbr % base_lenght - 10 + 'a';
		nbr = nbr / base_lenght;
	}
	return (str);
}
