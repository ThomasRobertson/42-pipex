/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:45:26 by troberts          #+#    #+#             */
/*   Updated: 2022/08/11 13:29:48 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy_static(char *dest, const char *src)
{
	ft_memcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len;
	char	*str;
	char	*ptr;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(*str) * (len + 1));
	ptr = str;
	if (str == NULL)
		return (NULL);
	ptr = ft_strcpy_static(ptr, s1);
	ptr = ptr + ft_strlen(s1);
	ptr = ft_strcpy_static(ptr, s2);
	free(s1);
	free(s2);
	return (str);
}
