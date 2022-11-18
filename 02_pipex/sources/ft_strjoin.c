/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:38:25 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/17 22:38:28 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

static char	*join(char *str, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	join(str, s1, s2);
	return (str);
}
