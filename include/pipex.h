/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:25:52 by troberts          #+#    #+#             */
/*   Updated: 2022/08/15 02:23:18 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>

# define PIPE_READ 0
# define PIPE_WRITE 1

# define FILE_1 0
# define FILE_2 1

# define RETURN_SUCCESS EXIT_SUCCESS
# define RETURN_FAILURE EXIT_FAILURE

typedef struct s_cmd
{
	char	*cmd_name;
	char	*path;
	char	**options;
	char	**envp;
}			t_cmd;

typedef struct s_pid
{
	int		pipefd[2];
	pid_t	pid;
}			t_pid;

t_cmd	*get_path_of_cmd(char **envp, char *cmd_char);
int		fork_and_execute_cmd(t_cmd **cmd_array, int fd_file[2]);
t_cmd	**create_struct_cmd(int argc, char **argv, char **envp);

void	perror_exit(char *str, int exit_status);

#endif