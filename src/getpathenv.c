/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpathenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:32:42 by troberts          #+#    #+#             */
/*   Updated: 2022/08/15 14:22:25 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*generate_cmd_path(char *path_env, char *cmd)
{
	char	*path_cmd;
	char	*path_cmd_tmp;

	if (path_env == NULL)
		return (NULL);
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

static t_cmd	*clean_error(char **array, t_cmd *cmd, char *str)
{
	ft_free_double_ptr(array);
	free_cmd(cmd);
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	return (NULL);
}

static t_cmd	*get_options(char *cmd_char, char **envp)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->options = ft_split(cmd_char, ' ');
	cmd->cmd_name = cmd->options[0];
	cmd->envp = envp;
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
	cmd = get_options(cmd_char, envp);
	cmd->path = generate_cmd_path(path_env[0], cmd->cmd_name);
	if (cmd->path == NULL)
		clean_error(path_env, cmd, NULL);
	i = 1;
	while (access(cmd->path, F_OK | X_OK) != 0)
	{
		free(cmd->path);
		i++;
		if (path_env[i] == NULL)
			return (clean_error(path_env, cmd, "No valid path found.\n"));
		cmd->path = generate_cmd_path(path_env[i], cmd->cmd_name);
		if (cmd->path == NULL)
			return (clean_error(path_env, cmd, NULL));
	}
	ft_free_double_ptr(path_env);
	return (cmd);
}
