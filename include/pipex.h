/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:25:52 by troberts          #+#    #+#             */
/*   Updated: 2022/09/18 22:00:57 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define _GNU_SOURCE 1

# include "../libft/include/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>

# define PIPE_READ 0
# define PIPE_WRITE 1

# define FILE_1 0
# define FILE_2 1

# define RETURN_SUCCESS EXIT_SUCCESS
# define RETURN_FAILURE EXIT_FAILURE

# define EXIT_CMD_NOT_FOUND 127

typedef struct s_cmd
{
	char	*cmd_name;
	char	*path;
	char	**options;
	char	**envp;
	pid_t	pid;
}			t_cmd;

typedef struct s_split
{
	char	*start;
	size_t	len;
	size_t	offset_add;
	char	delimiter;
	t_bool	is_pair;
}			t_split;

t_cmd	*get_path_of_cmd(char **envp, char *cmd_char);
int		fork_and_execute_cmd(t_cmd **cmd_array, int fd_file[2]);
t_cmd	**create_struct_cmd(int argc, char **argv, char **envp, int offset);

int		here_doc(char *limiter);

void	free_cmd_array(t_cmd **cmd_array);
void	free_cmd(t_cmd *cmd);
void	perror_exit(char *str, int exit_status);
int		perror_return(char *str, int exit_status);

#endif