/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:23:37 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/03/26 16:51:37 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*srce;
	size_t	i;

	dest = (char *)dst;
	srce = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = srce[i];
		++i;
	}
	return (dst);
}
