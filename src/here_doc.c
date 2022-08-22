/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:44:33 by troberts          #+#    #+#             */
/*   Updated: 2022/08/19 19:13:48 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_input_stdin(char *limiter)
{
	char	*line;
	char	*input_stdin;

	input_stdin = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		input_stdin = ft_strjoin_free(input_stdin, line);
		if (ft_strnstr(input_stdin, limiter, ft_strlen(input_stdin)))
			break ;
	}
	return (input_stdin);
}

int	here_doc(char *limiter)
{
	int		pipefd[2];
	char	*input_stdin;
	char	*input_heredoc;
	char	*pos_limiter;
	size_t	len_input_heredoc;

	if (pipe(pipefd) == -1)
		perror_return("here_doc: ", -1);
	input_stdin = get_input_stdin(limiter);
	pos_limiter = ft_strnstr(input_stdin, limiter, ft_strlen(input_stdin));
	if (pos_limiter == NULL)
	{
		ft_printf("Error: cannot find limiter for heredoc");
		return (-1);
	}
	len_input_heredoc = pos_limiter - input_stdin;
	input_heredoc = malloc(sizeof(*input_heredoc) * (len_input_heredoc + 1));
	ft_strlcpy(input_heredoc, input_stdin, (len_input_heredoc + 1));
	ft_putstr_fd(input_heredoc, pipefd[PIPE_WRITE]);
	close(pipefd[PIPE_WRITE]);
	free(input_stdin);
	free(input_heredoc);
	return (pipefd[PIPE_READ]);
}
