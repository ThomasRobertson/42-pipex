/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:47:54 by troberts          #+#    #+#             */
/*   Updated: 2022/04/21 22:50:54 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	ft_bzero((void *)dest, n);
	if (ft_strlen(src) < n)
		ft_memcpy(dest, src, ft_strlen(src));
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
