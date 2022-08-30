/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:51:52 by troberts          #+#    #+#             */
/*   Updated: 2022/08/30 13:02:45 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

#include "pipex.h"

static t_split	end_word_if_space(char *cmd_char, t_split *word)
{
	char	*pos_space;
	char	*pos_double;
	char	*pos_single;

	word->delimiter = ' ';
	word->is_pair = true;
	word->start = cmd_char;
	pos_space = ft_strchr((cmd_char + 1), ' ');
	pos_double = ft_strchr((cmd_char + 1), '"');
	pos_single = ft_strchr((cmd_char + 1), '\'');
	if (pos_space == NULL)
	{
		if (pos_single)
		{
			if (pos_double)
			{
				if (pos_single < pos_double)
					word->len = pos_single - cmd_char;
				else if (pos_single > pos_double)
					word->len = pos_double - cmd_char;
			}
			else
				word->len = pos_single - cmd_char;
		}
	}
	else
		word->len = pos_space - cmd_char;
	return (*word);
}

static t_split	find_quote(char	*cmd_char, char quote)
{
	char	*word_start;
	char	*word_end;
	t_split	word;

	word_start = ft_strchr(cmd_char, quote);
	if (word_start)
	{
		word_end = ft_strchr((cmd_char + 1), quote);
		if (quote == ' ')
			return (end_word_if_space(cmd_char, &word));
		else if (word_end)
		{
			word.start = word_start;
			word.len = word_end - word_start;
			word.delimiter = quote;
			word.is_pair = true;
			return (word);
		}
	}
	else
		word.is_pair = false;
	word.offset_add = 0;
	while (cmd_char[word.offset_add] == quote)
		word.offset_add++;
	return (word);
}

static t_split	get_next_word(char	*cmd_char, size_t offset)
{
	t_split	word_single;
	t_split	word_double;
	t_split	word_space;

	word_single = find_quote((cmd_char + offset), '\'');
	word_double = find_quote((cmd_char + offset), '"');
	word_space = find_quote((cmd_char + offset), ' ');
	if (word_single.is_pair
		&& (!word_double.is_pair || word_single.start < word_double.start)
		&& (!word_space.is_pair || word_single.start < word_space.start))
		return (word_single);
	else if (word_double.is_pair
		&& (!word_single.is_pair || word_double.start < word_single.start)
		&& (!word_space.is_pair || word_double.start < word_space.start))
		return (word_double);
	else if (word_space.is_pair)
		return (word_space);
	word_space.start = cmd_char + offset;
	word_space.delimiter = '\0';
	word_space.len = ft_strlen(cmd_char + offset);
	return (word_space);
}

static size_t	count_nbr_words(char *cmd_char)
{
	size_t	nbr;
	size_t	offset;
	t_split	word;

	nbr = 0;
	offset = 0;
	while (cmd_char[offset] != '\0'
		&& get_next_word(cmd_char, offset).start)
	{
		word = get_next_word(cmd_char, offset);
		offset += word.len + word.offset_add;
		nbr++;
		printf("word : %s, len: %lli", word.start, word.len);
	}
	printf("nbr: %zu\n", nbr);
	return (nbr);
}

char	**split_options(char *cmd_char)
{
	size_t	offset;
	size_t	nbr_word;
	size_t	i;
	t_split	word;
	char	**options;

	offset = 0;
	nbr_word = count_nbr_words(cmd_char);
	options = malloc(sizeof(*options) * (nbr_word + 1));
	options[nbr_word] = NULL;
	i = 0;
	while (i < nbr_word)
	{
		word = get_next_word(cmd_char, offset);
		options[i] = malloc(sizeof(**options) * (word.len + 1));
		ft_strlcpy(options[i], word.start, (word.len + 1));
		offset += word.len + word.offset_add;
		i++;
	}
	return (options);
}

int main(int argc, char **argv)
{
	char **options;
	options = split_options(argv[1]);
	int i = 0;
	while (options[i])
	{
		printf("%s\n", options[i]);
		i++;
	}
	return (0);
}

*/