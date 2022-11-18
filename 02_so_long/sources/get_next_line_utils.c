/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:11:02 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:11:03 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *c)
{
	int	len;

	len = 0;
	while (c && c[len] != '\0')
		len++;
	return (len);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == (char)(c))
			return ((char *)(s));
		else
			s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	ptr = malloc((ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1) * sizeof(*s1));
	if (!ptr)
		return (0);
	while (s1 && s1[++i])
		ptr[i] = s1[i];
	while (s2 && s2[++j])
		ptr[i++] = s2[j];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}
