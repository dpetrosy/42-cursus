/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:37:54 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/03/19 15:49:42 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	srce[1000];
	char	*sss;
	size_t	i;

	dest = (char *)dst;
	sss = ft_memcpy(srce, src, len);
	i = 0;
	while (i < len)
	{
		dest[i] = sss[i];
		++i;
	}
	return (dst);
}
