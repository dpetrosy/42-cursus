/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:39:05 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/04/15 20:52:32 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words_count(char const *s, const char c);
static int		split_str(char *str, char **words, char c, t_indexes *sp_ind);
static size_t	word_len(size_t i, char const *str, const char c);
static void		ft_free(char **words, size_t alloc_count);

char	**ft_split(char const *s, char c)
{
	unsigned int	words_count;
	char			**words;
	unsigned int	alloc_count;
	t_indexes		split_indexes;

	words_count = get_words_count(s, c);
	words = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!words)
		return (0);
	split_indexes.i = 0;
	split_indexes.j = 0;
	split_indexes.k = 0;
	split_indexes.alloc_count = 0;
	alloc_count = split_str((char *)s, words, c, &split_indexes);
	if (alloc_count < words_count)
	{
		ft_free(words, alloc_count);
		return (0);
	}
	words[words_count] = 0;
	return (words);
}

static size_t	get_words_count(char const *s, const char c)
{
	size_t			i;
	unsigned int	words_count;

	i = 0;
	words_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			++i;
		else
		{
			++words_count;
			while (s[i] != c && s[i])
				++i;
		}
	}
	return (words_count);
}

static int	split_str(char *str, char **words, char c, t_indexes *sp_ind)
{
	while (str[sp_ind->i])
	{
		if (str[sp_ind->i] != c)
		{
			words[sp_ind->j] = (char *)malloc(word_len(sp_ind->i, str, c) + 1);
			if (!words[sp_ind->j])
				return (sp_ind->alloc_count);
			else
				++sp_ind->alloc_count;
			sp_ind->k = 0;
			while (str[sp_ind->i] && str[sp_ind->i] != c)
				words[sp_ind->j][sp_ind->k++] = str[sp_ind->i++];
			words[sp_ind->j][sp_ind->k] = '\0';
			++sp_ind->j;
		}
		else
			++sp_ind->i;
	}
	return (sp_ind->alloc_count);
}

static size_t	word_len(size_t i, char const *str, const char c)
{
	size_t	size;

	size = 0;
	while (str[i] && str[i] != c)
	{
		++size;
		++i;
	}
	return (size);
}

static void	ft_free(char **words, size_t alloc_count)
{
	size_t	i;

	i = 0;
	while (i < alloc_count)
	{
		free(words[i]);
		++i;
	}
}
