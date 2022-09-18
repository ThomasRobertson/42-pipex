/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:36:08 by troberts          #+#    #+#             */
/*   Updated: 2022/09/18 22:00:49 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->path)
		ft_strdel(&cmd->path);
	while (cmd->options[i])
	{
		ft_strdel(&cmd->options[i]);
		i++;
	}
	free(cmd->options);
	free(cmd);
}

void	free_cmd_array(t_cmd **cmd_array)
{
	int	i;

	if (cmd_array == NULL)
		return ;
	i = 0;
	while (cmd_array[i])
	{
		free_cmd(cmd_array[i]);
		i++;
	}
	free(cmd_array);
}

t_cmd	**create_struct_cmd(int argc, char **argv, char **envp, int offset)
{
	int		j;
	t_cmd	**cmd_array;

	cmd_array = malloc(sizeof(*cmd_array) * (argc - offset));
	if (cmd_array == NULL)
		return (NULL);
	cmd_array[argc - offset - 1] = NULL;
	j = 0;
	while (j + offset < (argc - 1))
	{
		cmd_array[j] = get_path_of_cmd(envp, argv[j + offset]);
		if (cmd_array[j] == NULL)
		{
			free_cmd_array(cmd_array);
			return (NULL);
		}
		j++;
	}
	return (cmd_array);
}
