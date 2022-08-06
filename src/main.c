/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:25:28 by troberts          #+#    #+#             */
/*   Updated: 2022/08/06 11:40:16 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_path;
	char	*options[3];
	char	*cmd;

	(void)argc;
	(void)argv;
	options[0] = "ls";
	options[1] = "-la";
	options[2] = NULL;
	cmd = "ls";
	cmd_path = get_path_of_cmd(envp, cmd);
	execve(cmd_path, options, envp);
	return (0);
}
