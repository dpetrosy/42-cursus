/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:31:17 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/12 15:25:53 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	max;

	max = 1;
	if (nb < 0 && nb / 10 == 0)
		ft_putchar('-', fd);
	if (nb < 0)
		max = -1;
	if (nb / 10 != 0)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar(((nb % 10) * max) + '0', fd);
}
