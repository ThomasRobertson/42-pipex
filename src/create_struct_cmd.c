/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:36:08 by troberts          #+#    #+#             */
/*   Updated: 2022/08/19 19:16:01 by troberts         ###   ########.fr       */
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

	i = 0;
	while (cmd_array[i])
	{
		free_cmd(cmd_array[i]);
		i++;
	}
	free(cmd_array);
}

t_cmd	**create_struct_cmd_heredoc(char **argv, char **envp)
{
	int		i;
	t_cmd	**cmd_array;

	cmd_array = malloc(sizeof(*cmd_array) * (2 + 1));
	cmd_array[2] = NULL;
	if (cmd_array == NULL)
		return (NULL);
	i = 0;
	while (i < 2)
	{
		cmd_array[i] = get_path_of_cmd(envp, argv[i + 3]);
		if (cmd_array[i] == NULL)
		{
			free_cmd_array(cmd_array);
			return (NULL);
		}
		i++;
	}
	return (cmd_array);
}

t_cmd	**create_struct_cmd(int argc, char **argv, char **envp)
{
	int		i;
	int		j;
	t_cmd	**cmd_array;

	cmd_array = malloc(sizeof(*cmd_array) * (argc - 2));
	cmd_array[argc - 3] = NULL;
	if (cmd_array == NULL)
		return (NULL);
	i = 2;
	j = 0;
	while (i < (argc - 1))
	{
		cmd_array[j] = get_path_of_cmd(envp, argv[i]);
		if (cmd_array[j] == NULL)
		{
			free_cmd_array(cmd_array);
			return (NULL);
		}
		i++;
		j++;
	}
	return (cmd_array);
}
