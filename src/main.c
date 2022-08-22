/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:25:28 by troberts          #+#    #+#             */
/*   Updated: 2022/08/23 01:08:10 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_cmd	**here_doc_main(int (*fd_file)[2], int argc, char **argv, \
																char **envp)
{
	t_cmd	**cmd_array;

	if (argc != 6)
		ft_exit_print("Need 5 args for heredoc.", STDERR_FILENO, EXIT_FAILURE);
	(*fd_file)[FILE_1] = here_doc(argv[2]);
	if ((*fd_file)[FILE_1] == -1)
	{
		ft_printf("bash: %s:", argv[1]);
		perror("");
	}
	(*fd_file)[FILE_2] = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if ((*fd_file)[FILE_2] == -1)
		perror_exit("main: Cannot open file2", 1);
	cmd_array = create_struct_cmd_heredoc(argv, envp);
	if (cmd_array == NULL)
		perror_exit("main: Cannot create cmd_array", 1);
	return (cmd_array);
}

static t_cmd	**not_here_doc(int (*fd_file)[2], int argc, char **argv, \
																char **envp)
{
	t_cmd	**cmd_array;

	(*fd_file)[FILE_1] = open(argv[1], O_RDONLY);
	if ((*fd_file)[FILE_1] == -1)
	{
		ft_printf("bash: %s:", argv[1]);
		perror("");
	}
	(*fd_file)[FILE_2] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, \
																		0644);
	if ((*fd_file)[FILE_2] == -1)
		perror_exit("main: Cannot open file2", 1);
	cmd_array = create_struct_cmd(argc, argv, envp);
	if (cmd_array == NULL)
		perror_exit("main: Cannot create cmd_array", 1);
	return (cmd_array);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_file[2];
	t_cmd	**cmd_array;
	int		return_status;

	if (argc < 5)
		ft_exit_print("Not enought arguments.", STDERR_FILENO, EXIT_FAILURE);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		cmd_array = here_doc_main(&fd_file, argc, argv, envp);
	else
		cmd_array = not_here_doc(&fd_file, argc, argv, envp);
	if (cmd_array == NULL)
		perror_exit("main: Cannot create cmd_array", 1);
	return_status = fork_and_execute_cmd(cmd_array, fd_file);
	free_cmd_array(cmd_array);
	close(fd_file[FILE_1]);
	close(fd_file[FILE_2]);
	return (return_status);
}
