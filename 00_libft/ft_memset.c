/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:48:41 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/04/02 19:16:06 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*char_ptr;
	unsigned char	ch;
	size_t			i;

	char_ptr = (char *)b;
	i = 0;
	ch = (unsigned char)c;
	while (i < len)
	{
		char_ptr[i] = ch;
		++i;
	}
	return (b);
}
