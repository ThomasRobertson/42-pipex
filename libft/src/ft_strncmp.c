/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:12:30 by troberts          #+#    #+#             */
/*   Updated: 2022/04/10 23:18:19 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 > n || len_s2 > n)
		return (ft_memcmp(s1, s2, n));
	if (len_s1 < len_s2)
		return (ft_memcmp(s1, s2, len_s1 + 1));
	else
		return (ft_memcmp(s1, s2, len_s2 + 1));
}
