/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:42:56 by troberts          #+#    #+#             */
/*   Updated: 2022/08/07 16:43:49 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_double_ptr(char **array_char)
{
	size_t	i;

	i = 0;
	while (array_char[i])
	{
		free(array_char[i]);
		i++;
	}
	free(array_char);
}
