/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:59:22 by gverdyan          #+#    #+#             */
/*   Updated: 2022/03/22 21:50:04 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	int		start;
	int		end;
	char	*str;

	s1_len = ft_strlen(s1);
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		++start;
	end = s1_len - 1;
	while (ft_strchr(set, s1[end]) && end >= start)
		--end;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
