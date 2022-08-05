/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:59:24 by troberts          #+#    #+#             */
/*   Updated: 2022/05/02 15:46:35 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nbr;

	len = nbrlen(n);
	str = malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = 0;
	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	if (nbr == 0)
		str[0] = '0';
	while (len && nbr)
	{
		len--;
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}
