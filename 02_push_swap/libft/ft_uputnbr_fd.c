/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 04:02:38 by gverdyan          #+#    #+#             */
/*   Updated: 2022/04/16 18:50:27 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_uputnbr_fd(unsigned int n, int fd)
{
	size_t	nb;

	nb = n;
	if (nb / 10 != 0)
		ft_uputnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
