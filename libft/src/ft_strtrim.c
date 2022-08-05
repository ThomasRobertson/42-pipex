/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 02:00:11 by troberts          #+#    #+#             */
/*   Updated: 2022/06/16 03:01:47 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charinset(char c, char const *set)
{
	if (ft_strchr(set, c) == NULL)
		return (0);
	return (1);
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

static size_t	trim_counter(char const *s1, char const *set, size_t *start)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (charinset(s1[i], set))
	{
		if (s1[i] == '\0')
			return (len);
		len++;
		i++;
		(*start)++;
	}
	i = ft_strlen(s1) - 1;
	while (charinset(s1[i], set))
	{
		len++;
		i--;
	}
	return (len);
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*str;
	char	*ptr;
	size_t	start;

	if (ft_strlen(s1) == 0)
		return (ft_strnew_static(0));
	start = 0;
	len = ft_strlen(s1) - trim_counter(s1, set, &start);
	str = ft_strnew_static(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	ptr = (char *)s1;
	ptr = ptr + start;
	str = ft_strncpy_static(str, ptr, len);
	return (str);
}
