/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:44:05 by troberts          #+#    #+#             */
/*   Updated: 2022/08/19 19:06:26 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	perror_exit(char *str, int exit_status)
{
	perror(str);
	exit(exit_status);
}

int	perror_return(char *str, int exit_status)
{
	perror(str);
	return (exit_status);
}
