/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 05:03:50 by troberts          #+#    #+#             */
/*   Updated: 2022/06/16 03:02:01 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			cnt++;
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (cnt);
}

static char	**nullerror(char **str, size_t i)
{
	while (i)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (NULL);
}

static char	*ft_strncpy_static(char *dest, const char *src, size_t n)
{
	ft_bzero((void *)dest, n);
	if (ft_strlen(src) < n)
		ft_memcpy(dest, src, ft_strlen(src));
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

static char	*nword(char **ptr, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	while (**ptr == c && **ptr)
		(*ptr)++;
	while ((*ptr)[len] != c && (*ptr)[len])
		len++;
	word = malloc(sizeof(*word) * (len + 1));
	if (word == NULL)
		return (NULL);
	word = ft_strncpy_static(word, *ptr, len);
	word[len] = 0;
	(*ptr) += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	nbr_word;
	size_t	i;
	char	*ptr;

	nbr_word = count_word(s, c);
	str = malloc(sizeof(*str) * (nbr_word + 1));
	if (str == NULL)
		return (NULL);
	ptr = (char *)s;
	i = 0;
	while (i < nbr_word)
	{
		str[i] = nword(&ptr, c);
		if (str[i] == NULL)
			return (nullerror(str, i));
		i++;
	}
	str[nbr_word] = 0;
	return (str);
}
