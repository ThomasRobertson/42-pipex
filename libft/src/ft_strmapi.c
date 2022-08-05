/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 01:43:58 by troberts          #+#    #+#             */
/*   Updated: 2022/06/16 03:02:12 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew_static(size_t size)
{
	char	*str;

	str = malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (size > 0)
	{
		str[size] = 0;
		size--;
	}
	str[0] = 0;
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = ft_strnew_static(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = (char)f(i, s[i]);
		i++;
	}
	return (str);
}
