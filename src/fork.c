/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:48:25 by troberts          #+#    #+#             */
/*   Updated: 2022/08/15 02:38:34 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pid	launch_child_process(t_cmd *cmd, int fd_stdin)
{
	t_pid	pid;

	pipe(pid.pipefd);
	pid.pid = fork();
	if (pid.pid == -1)
		perror_exit("", EXIT_FAILURE);
	if (pid.pid == 0)
	{
		dup2(fd_stdin, STDIN_FILENO);
		dup2(pid.pipefd[PIPE_WRITE], STDOUT_FILENO);
		close(pid.pipefd[PIPE_READ]);
		close(pid.pipefd[PIPE_WRITE]);
		execve(cmd->path, cmd->options, cmd->envp);
		exit(EXIT_FAILURE);
	}
	ft_printf("Child %i born.\n", pid.pid);
	close(pid.pipefd[PIPE_WRITE]);
	return (pid);
}

static int	size_of_array(t_cmd **cmd_array)
{
	int	i;

	i = 0;
	while (cmd_array[i])
		i++;
	return (i);
}

int	fork_and_execute_cmd(t_cmd **cmd_array, int fd_file[2])
{
	int		nbr_cmd;
	int		i;
	int		fd_read;
	pid_t	status;
	t_pid	pid;

	nbr_cmd = size_of_array(cmd_array);
	i = 0;
	pid.pipefd[PIPE_READ] = fd_file[FILE_1];
	while (i < nbr_cmd)
	{
		fd_read = pid.pipefd[PIPE_READ];
		pid = launch_child_process(cmd_array[i], pid.pipefd[PIPE_READ]);
		close(fd_read);
		i++;
	}
/* 	status = wait(NULL);
	while (status > 0)
	{
		status = wait(NULL);
		ft_putendl("A child has died.");
		if (status == -1 && errno != ECHILD)
		{
			perror("");
			return (RETURN_FAILURE);
		}
	} */
	while((status = wait(NULL)) > 0)
	{
		ft_printf("Child %i has died.\n", status);
	}
	return (RETURN_SUCCESS);
}
