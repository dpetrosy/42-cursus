/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:38:37 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/17 22:38:41 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

static void	get_substr(char const *s, unsigned int start, size_t len, char *sub)
{
	size_t	i;

	i = 0;
	while (s[start] && i < len)
	{
		sub[i++] = s[start];
		start++;
	}
	sub[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	i = 0;
	if (s_len < start)
	{
		sub = (char *)malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[i] = '\0';
		return (sub);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	get_substr(s, start, len, sub);
	return (sub);
}
