/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:06:36 by gverdyan          #+#    #+#             */
/*   Updated: 2022/03/18 17:57:21 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new;

	new = NULL;
	while (*s)
	{
		if ((char) *s == (char) c)
			new = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (new);
}
