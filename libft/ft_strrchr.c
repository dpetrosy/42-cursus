/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:57:20 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/03/19 21:33:12 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		len;

	len = ft_strlen(s);
	ch = (unsigned char)c;
	while (len >= 0)
	{
		if (s[len] == ch)
		{
			return ((char *)(s + len));
		}
		--len;
	}
	return (0);
}
