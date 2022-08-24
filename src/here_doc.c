/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:44:33 by troberts          #+#    #+#             */
/*   Updated: 2022/08/24 19:05:51 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_input_stdin(char *limiter)
{
	char	*line;
	char	*input_stdin;
	size_t	len_limiter;

	len_limiter = ft_strlen(limiter);
	input_stdin = NULL;
	while (1)
	{
		ft_printf("> ");
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
		{
			ft_printf("bash: warning: here-document delimited by end-of-file");
			ft_printf(" (wanted `%s')\n", limiter);
			return (input_stdin);
		}
		else if (ft_strnstr(line, limiter, len_limiter) && \
										len_limiter == (ft_strlen(line) - 1))
		{
			free(line);
			return (input_stdin);
		}
		else
			input_stdin = ft_strjoin_free(input_stdin, line);
	}
}

int	here_doc(char *limiter)
{
	int		pipefd[2];
	char	*input_stdin;
	char	*input_heredoc;
	size_t	len_input;

	if (pipe(pipefd) == -1)
		perror_return("here_doc: ", -1);
	input_stdin = get_input_stdin(limiter);
	len_input = ft_strlen(input_stdin);
	input_heredoc = malloc(sizeof(*input_heredoc) * (len_input + 1));
	ft_strlcpy(input_heredoc, input_stdin, (len_input + 1));
	ft_putstr_fd(input_heredoc, pipefd[PIPE_WRITE]);
	close(pipefd[PIPE_WRITE]);
	free(input_stdin);
	free(input_heredoc);
	return (pipefd[PIPE_READ]);
}
