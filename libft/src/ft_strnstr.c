/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:45:07 by troberts          #+#    #+#             */
/*   Updated: 2022/04/11 00:43:04 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_l;

	if (little[0] == '\0')
		return ((char *)big);
	len_l = ft_strlen(little);
	while (*big != '\0' && len && len >= len_l)
	{
		if (!ft_strncmp(big, little, len_l))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
