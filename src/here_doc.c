/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:44:33 by troberts          #+#    #+#             */
/*   Updated: 2022/09/18 21:53:03 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_input_stdin(char *limiter)
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
	int		here_doc_fd;
	char	*input_heredoc;

	here_doc_fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (here_doc_fd == -1)
		return (-1);
	input_heredoc = get_input_stdin(limiter);
	ft_putstr_fd(input_heredoc, here_doc_fd);
	free(input_heredoc);
	close(here_doc_fd);
	return (1);
}
