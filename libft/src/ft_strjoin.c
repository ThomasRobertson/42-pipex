/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:45:26 by troberts          #+#    #+#             */
/*   Updated: 2022/06/24 12:18:35 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy_static(char *dest, const char *src)
{
	ft_memcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	char	*ptr;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew_static(len);
	ptr = str;
	if (str == NULL)
		return (NULL);
	ptr = ft_strcpy_static(ptr, s1);
	ptr = ptr + ft_strlen(s1);
	ptr = ft_strcpy_static(ptr, s2);
	return (str);
}
