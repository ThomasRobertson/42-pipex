/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpathenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:32:42 by troberts          #+#    #+#             */
/*   Updated: 2022/08/13 15:35:43 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*generate_cmd_path(char *path_env, char *cmd)
{
	char	*path_cmd;
	char	*path_cmd_tmp;

	path_cmd_tmp = ft_strjoin(ft_strchr(path_env, '/'), "/");
	if (path_cmd_tmp == NULL)
	{
		perror("Error");
		return (NULL);
	}
	path_cmd = ft_strjoin(path_cmd_tmp, cmd);
	free(path_cmd_tmp);
	return (path_cmd);
}

static void	clean_error(char **array, t_cmd *cmd, char *str)
{
	ft_free_double_ptr(array);
	cmd->cmd_name = NULL;
	ft_free_double_ptr(cmd->options);
	free(cmd->path);
	free(cmd);
	if (str)
		ft_exit_print(str, STDERR_FILENO, EXIT_FAILURE);
	exit(EXIT_FAILURE);
}

static t_cmd	*get_options(char *cmd_char)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->options = ft_split(cmd_char, ' ');
	cmd->cmd_name = cmd->options[0];
	return (cmd);
}

t_cmd	*get_path_of_cmd(char **envp, char *cmd_char)
{
	int		i;
	char	**path_env;
	t_cmd	*cmd;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	path_env = ft_split(envp[i], ':');
	cmd = get_options(cmd_char);
	i = 0;
	cmd->path = generate_cmd_path(path_env[i], cmd->cmd_name);
	if (cmd->path == NULL)
		clean_error(path_env, cmd, NULL);
	i++;
	while (access(cmd->path, F_OK | X_OK) != 0)
	{
		free(cmd->path);
		i++;
		if (path_env[i] == NULL)
			clean_error(path_env, cmd, "No valid path found for command.");
		cmd->path = generate_cmd_path(path_env[i], cmd->cmd_name);
		if (cmd->path == NULL)
			clean_error(path_env, cmd, NULL);
	}
	return (cmd);
}
