/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:48:25 by troberts          #+#    #+#             */
/*   Updated: 2022/09/19 20:14:29 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	launch_child_process(t_cmd *cmd, int fd_stdin, int fd_file2)
{
	int	pipefd[2];

	pipe(pipefd);
	cmd->pid = fork();
	if (cmd->pid == -1)
		perror("launch_child_process: Cannot launch child");
	else if (cmd->pid == 0)
	{
		dup2(fd_stdin, STDIN_FILENO);
		if (fd_file2 == -1)
			dup2(pipefd[PIPE_WRITE], STDOUT_FILENO);
		else
			dup2(fd_file2, STDOUT_FILENO);
		close(pipefd[PIPE_READ]);
		close(pipefd[PIPE_WRITE]);
		if (cmd->path == NULL)
			cmd->pid = -1;
		else
		{
			cmd->pid = execve(cmd->path, cmd->options, cmd->envp);
			ft_dprintf(2, "bash: %s: %s\n", cmd->path, strerror(errno));
		}
	}
	close(pipefd[PIPE_WRITE]);
	return (pipefd[PIPE_READ]);
}

int	size_of_array(t_cmd **cmd_array)
{
	int	i;

	i = 0;
	while (cmd_array[i])
		i++;
	return (i);
}

int	wait_for_child(t_cmd **cmd_array, int nbr_cmd)
{
	int		wstatus;
	pid_t	status;
	int		i;

	i = 0;
	while (i < nbr_cmd)
	{
		status = waitpid(cmd_array[i]->pid, &wstatus, 0);
		if (status == -1)
			perror("fork_and_execute_cmd: ");
		i++;
	}
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else
		return (EXIT_FAILURE);
}

int	fork_and_execute_cmd(t_cmd **cmd_array, int fd_file[2])
{
	int		nbr_cmd;
	int		i;
	int		fd_read;
	int		pipefd_read;

	nbr_cmd = size_of_array(cmd_array);
	i = 0;
	pipefd_read = fd_file[FILE_1];
	while (i < nbr_cmd)
	{
		fd_read = pipefd_read;
		if (i == (nbr_cmd - 1))
			pipefd_read = launch_child_process(cmd_array[i], pipefd_read, \
				fd_file[FILE_2]);
		else
			pipefd_read = launch_child_process(cmd_array[i], pipefd_read, -1);
		close(fd_read);
		if (cmd_array[i]->pid == -1 && cmd_array[i]->path == NULL)
			return (EXIT_CMD_NOT_FOUND);
		if (cmd_array[i]->pid == -1)
			return (EXIT_FAILURE);
		i++;
	}
	return (wait_for_child(cmd_array, nbr_cmd));
}
