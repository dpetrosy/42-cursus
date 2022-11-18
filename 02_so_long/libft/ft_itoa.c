/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:26:56 by gverdyan          #+#    #+#             */
/*   Updated: 2022/03/24 21:28:08 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strrev(char *str, size_t start, size_t end)
{
	char	t;

	while (start < end)
	{
		t = str[start];
		str[start++] = str[end];
		str[end--] = t;
	}
}

static void	solution(long int n, size_t index, char *s)
{
	size_t	i;

	i = index;
	if (n == 0)
	{
		s[0] = '0';
		return ;
	}
	while (n)
	{
		s[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	ft_strrev(s, index, i - 1);
}

static size_t	num_len(long int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*s;
	size_t		len;
	size_t		index;

	num = n;
	len = num_len(num);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	index = 0;
	if (num < 0)
	{
		s[0] = '-';
		++index;
		num *= -1;
	}
	s[len] = '\0';
	solution(num, index, s);
	return (s);
}
