/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:03:08 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/03/19 21:50:21 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*ret_ptr;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		ret_ptr = (char *)(haystack + i);
		while ((haystack[i + j] == needle[j]) && haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (ret_ptr);
			++j;
		}
		++i;
	}
	return (0);
}
