/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 04:19:33 by gverdyan          #+#    #+#             */
/*   Updated: 2022/03/20 13:48:15 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	is_space(const char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	init_number(int i, const char *str, int sign)
{
	int	number;

	number = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (sign * number);
}

static int	init_sign(int i, const char *str)
{
	int	sign;
	int	is_signed;

	is_signed = 0;
	sign = 1;
	if (!is_signed && str[i] == '+')
		is_signed = 1;
	if (!is_signed && str[i] == '-')
	{
		sign = -1;
		is_signed = 1;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	sign = init_sign(i, str);
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (init_number(i, str, sign));
		else
			break ;
	}
	return (0);
}
