/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:25:28 by troberts          #+#    #+#             */
/*   Updated: 2022/08/07 01:36:18 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*cmd_path;
	char	**options;

	(void)argc;
	cmd_path = get_path_of_cmd(envp, argv[1], &options);
	execve(cmd_path, options, envp);
	return (0);
}
