/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:25:52 by troberts          #+#    #+#             */
/*   Updated: 2022/08/06 11:26:27 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>

char	*get_path_of_cmd(char **enpv, char *cmd);

void	free_double_ptr_char(char **arr_char);
void	exit_print(char *str);

#endif