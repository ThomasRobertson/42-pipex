/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpathenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:32:42 by troberts          #+#    #+#             */
/*   Updated: 2022/09/19 18:33:57 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*generate_cmd_path(char *path_env, char *cmd)
{
	char	*path_cmd;
	char	*path_cmd_tmp;

	if (path_env == NULL)
		return (NULL);
	path_cmd_tmp = ft_strjoin(ft_strchr(path_env, '/'), "/");
	if (path_cmd_tmp == NULL)
	{
		perror("generate_cmd_path: Malloc return NULL");
		return (NULL);
	}
	path_cmd = ft_strjoin(path_cmd_tmp, cmd);
	free(path_cmd_tmp);
	return (path_cmd);
}

t_cmd	*clean_error(t_cmd *cmd, t_bool display_message, \
								t_bool return_null)
{
	if (display_message)
		ft_printf("bash: %s: command not found\n", cmd->cmd_name);
	if (return_null == true)
	{
		free_cmd(cmd);
		return (NULL);
	}
	else
	{
		cmd->path = NULL;
		return (cmd);
	}
}

t_cmd	*get_options(char *cmd_char, char **envp)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->options = ft_split(cmd_char, ' ');
	if (cmd->options == NULL)
	{
		free(cmd);
		return (NULL);
	}
	cmd->cmd_name = cmd->options[0];
	cmd->envp = envp;
	return (cmd);
}

t_cmd	*test_correct_access_cmd(t_cmd *cmd, char **path_env)
{
	int	i;

	cmd->path = ft_strdup(cmd->cmd_name);
	if (cmd->path == NULL)
		return (clean_error(cmd, false, true));
	if (ft_strchr(cmd->path, '/'))
		return (cmd);
	free(cmd->path);
	i = 0;
	while (path_env[i])
	{
		cmd->path = generate_cmd_path(path_env[i], cmd->cmd_name);
		if (cmd->path == NULL)
			return (clean_error(cmd, false, true));
		if (access(cmd->path, F_OK | X_OK) == 0)
			break ;
		ft_strdel(&(cmd->path));
		i++;
	}
	if (path_env[i] == NULL)
		return (clean_error(cmd, true, false));
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
	if (path_env == NULL)
		return (NULL);
	cmd = get_options(cmd_char, envp);
	if (cmd == NULL)
	{
		ft_free_double_ptr(path_env);
		return (NULL);
	}
	cmd = test_correct_access_cmd(cmd, path_env);
	ft_free_double_ptr(path_env);
	return (cmd);
}
