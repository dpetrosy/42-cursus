/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:27:30 by gverdyan          #+#    #+#             */
/*   Updated: 2022/04/02 23:05:52 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			++i;
		else
		{
			++count;
			while (s[i] != c && s[i])
				++i;
		}
	}
	return (count);
}

static size_t	char_count(char const *s, char c, size_t start)
{
	size_t	count;

	count = 0;
	while (s[start] == c && s[start])
		++start;
	while (s[start])
	{
		if (s[start] == c)
			break ;
		count++;
		start++;
	}
	return (count + 1);
}

static void	ft_free(char **ptr, size_t ptr_idx)
{
	size_t	i;

	i = 0;
	while (i < ptr_idx)
	{
		free(ptr[i]);
		i++;
	}
}

static int	spalloc(char **vec, char const *str, char c, size_t word_count)
{
	size_t	vec_i;
	size_t	str_i;
	size_t	count;
	size_t	vec_str_i;

	vec_i = 0;
	str_i = 0;
	while (vec_i < word_count)
	{
		count = char_count(str, c, str_i);
		vec[vec_i] = (char *)malloc(sizeof(char) * count);
		if (!vec[vec_i])
		{
			ft_free(vec, vec_i);
			return (0);
		}
		vec_str_i = 0;
		while (str[str_i] == c)
			str_i++;
		while (vec_str_i < count - 1)
			vec[vec_i][vec_str_i++] = str[str_i++];
		vec[vec_i++][vec_str_i] = '\0';
		str_i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**vec;
	size_t	w_cnt;
	int		is_alloc;

	w_cnt = word_count(s, c);
	vec = (char **)malloc(sizeof(char *) * (w_cnt + 1));
	if (!vec)
		return (NULL);
	is_alloc = spalloc(vec, s, c, w_cnt);
	vec[w_cnt] = NULL;
	if (is_alloc == 0)
	{
		free(vec);
		return (NULL);
	}
	return (vec);
}
