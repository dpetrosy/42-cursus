/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 02:18:38 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/12 16:30:52 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTNBR_BASE_H
# define FT_PUTNBR_BASE_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <unistd.h>
# include <unistd.h>

size_t	ft_putnbr_base(ssize_t nbr, char *base, size_t len, char spf);
void	print_base(ssize_t num, char *base, size_t len, size_t *count);

#endif  /* FT_PUTNBR_BASE_H */
