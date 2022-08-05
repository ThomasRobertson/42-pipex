/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:45:11 by troberts          #+#    #+#             */
/*   Updated: 2022/06/16 03:00:51 by troberts         ###   ########.fr       */
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

static char	*ft_strncpy_static(char *dest, const char *src, size_t n)
{
	ft_bzero((void *)dest, n);
	if (ft_strlen(src) < n)
		ft_memcpy(dest, src, ft_strlen(src));
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strnew_static(0));
	if ((len_s - start) < len)
		len = len_s - start;
	sub = ft_strnew_static(len);
	if (sub == NULL)
		return (NULL);
	ft_strncpy_static(sub, s + start, len);
	return (sub);
}
