/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:48:25 by troberts          #+#    #+#             */
/*   Updated: 2022/08/19 10:49:29 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pid	launch_child_process(t_cmd *cmd, int fd_stdin, int fd_file2)
{
	t_pid	pid;

	if (cmd->path == NULL)
	{
		pid.pid = 1;
		return (pid);
	}
	pipe(pid.pipefd);
	pid.pid = fork();
	if (pid.pid == -1)
		perror("launch_child_process: Cannot launch child");
	else if (pid.pid == 0)
	{
		dup2(fd_stdin, STDIN_FILENO);
		if (fd_file2 == -1)
			dup2(pid.pipefd[PIPE_WRITE], STDOUT_FILENO);
		else
			dup2(fd_file2, STDOUT_FILENO);
		close(pid.pipefd[PIPE_READ]);
		close(pid.pipefd[PIPE_WRITE]);
		execve(cmd->path, cmd->options, cmd->envp);
		perror("launch_child_process: Error with execve.");
		pid.pid = -1;
	}
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
	int		wstatus;
	pid_t	status;
	t_pid	pid;
	int		exit_status;

	nbr_cmd = size_of_array(cmd_array);
	i = 0;
	pid.pipefd[PIPE_READ] = fd_file[FILE_1];
	while (i < nbr_cmd)
	{
		fd_read = pid.pipefd[PIPE_READ];
		if (i == (nbr_cmd - 1))
			pid = launch_child_process(cmd_array[i], pid.pipefd[PIPE_READ], \
				fd_file[FILE_2]);
		else
			pid = launch_child_process(cmd_array[i], pid.pipefd[PIPE_READ], -1);
		close(fd_read);
		if (pid.pid == -1)
			return (EXIT_FAILURE);
		i++;
	}
	exit_status = EXIT_SUCCESS;
	status = wait(&wstatus);
	while (status > 0)
	{
		status = wait(&wstatus);
		if (status == -1 && errno != ECHILD)
		{
			perror("fork_and_execute_cmd: Other error than no more child");
			exit_status = EXIT_FAILURE;
		}
	}
	if (exit_status == EXIT_FAILURE)
		return (exit_status);
	else if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else
		return (EXIT_SUCCESS);
}
