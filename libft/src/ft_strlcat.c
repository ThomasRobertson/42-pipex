/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:47:55 by troberts          #+#    #+#             */
/*   Updated: 2022/04/10 01:07:38 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dtmp;
	size_t	len_dst;
	size_t	len_src;
	size_t	n;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size == 0 || len_dst >= size)
		return (size + len_src);
	if (len_src == 0)
		return (len_dst);
	dtmp = dst + len_dst;
	if (len_src <= (size - len_dst - 1))
		n = len_src;
	else
		n = size - len_dst - 1;
	ft_memcpy(dtmp, src, n);
	dtmp[n] = 0;
	return (len_dst + len_src);
}
