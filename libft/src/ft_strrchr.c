/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:34:19 by troberts          #+#    #+#             */
/*   Updated: 2022/04/19 21:47:51 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*memrchr(const void *s, int c, size_t n)
{
	s = s + n - 1;
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s--;
		n--;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	return (memrchr(s, c, ft_strlen(s) + 1));
}
