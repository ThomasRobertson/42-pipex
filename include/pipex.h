/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:25:52 by troberts          #+#    #+#             */
/*   Updated: 2022/08/13 15:29:21 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_cmd
{
	char	*cmd_name;
	char	*path;
	char	**options;
}			t_cmd;

t_cmd	*get_path_of_cmd(char **envp, char *cmd_char);

void	free_double_ptr_char(char **arr_char);

#endif