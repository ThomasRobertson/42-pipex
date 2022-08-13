/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:25:28 by troberts          #+#    #+#             */
/*   Updated: 2022/08/13 15:17:40 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;

	(void)argc;
	cmd = get_path_of_cmd(envp, argv[1]);
	execve(cmd->path, cmd->options, envp);
	return (0);
}
