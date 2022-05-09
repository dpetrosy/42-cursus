/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 01:58:05 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/03/22 20:11:02 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_num_size(long int num);
static void			get_str(char *str, unsigned int index, long int num);
static void			ft_strrev(char *str, unsigned int index, size_t i);

char	*ft_itoa(int n)
{
	char			*str;
	int				num_size;
	long int		num;
	int				minus;
	unsigned int	start_index;

	num = n;
	num_size = get_num_size(num);
	minus = 1;
	start_index = 0;
	if (num < 0)
	{
		minus = -1;
		start_index = 1;
		++num_size;
		num = -num;
	}
	str = (char *)malloc(num_size + 1);
	if (!str)
		return (0);
	if (minus == -1)
		str[0] = '-';
	get_str(str, start_index, num);
	return (str);
}

static unsigned int	get_num_size(long int num)
{
	unsigned int	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		++size;
		num = num / 10;
	}
	return (size);
}

static void	get_str(char *str, unsigned int index, long int num)
{
	size_t	i;

	i = index;
	if (num == 0)
	{
		str[0] = '0';
		++i;
	}
	else
	{
		while (num != 0)
		{
			str[i] = (num % 10) + '0';
			num = num / 10;
			++i;
		}
	}
	str[i] = '\0';
	ft_strrev(str, index, i);
}

static void	ft_strrev(char *str, unsigned int index, size_t i)
{
	size_t	start;
	size_t	end;	
	char	temp;

	start = index;
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		++start;
		--end;
	}
}
