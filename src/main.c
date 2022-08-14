/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:25:28 by troberts          #+#    #+#             */
/*   Updated: 2022/08/15 02:23:42 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd_file[2];
	t_cmd	**cmd_array;

	(void)argc;
	fd_file[FILE_1] = open(argv[1], O_RDONLY);
	if (fd_file[FILE_1] == -1)
		perror_exit("", 1);
	fd_file[FILE_2] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	if (fd_file[FILE_2] == -1)
		perror_exit("", 1);
	cmd_array = create_struct_cmd(argc, argv, envp);
	if (cmd_array == NULL)
		perror_exit("", 1);
	fork_and_execute_cmd(cmd_array, fd_file);
	close(fd_file[FILE_1]);
	close(fd_file[FILE_2]);
	return (0);
}
