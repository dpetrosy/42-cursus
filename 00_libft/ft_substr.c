/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:43:15 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/04/21 19:44:37 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	unsigned int	len_s;

	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	if (len > len_s - start)
		len = len_s - start;
	substr = (char *)malloc(len + 1);
	i = 0;
	if (!substr)
		return (0);
	while (i < len && s[start])
	{
		substr[i] = s[start];
		++start;
		++i;
	}
	substr[i] = '\0';
	return (substr);
}
