/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:41:16 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:41:18 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = file_read(fd, str);
	if (!str)
		return (NULL);
	next_line = ret_line(str);
	str = updated_str(str);
	return (next_line);
}

char	*file_read(int fd, char *str)
{
	char	*temp;
	int		read_len;

	temp = (char *)malloc((BUFFER_SIZE + 1) + sizeof(char));
	if (!temp)
		return (NULL);
	read_len = 1;
	while (read_len != 0 && !ft_gnl_strchr(str, '\n'))
	{
		read_len = read(fd, temp, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[read_len] = '\0';
		str = ft_gnl_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*ret_line(char *str)
{
	char	*line;
	size_t	idx;

	idx = 0;
	if (!str[idx])
		return (NULL);
	while (str[idx] && str[idx] != '\n')
		idx++;
	line = (char *)malloc((idx + 2) * sizeof(char));
	if (!line)
		return (NULL);
	idx = 0;
	while (str[idx] && str[idx] != '\n')
	{
		line[idx] = str[idx];
		idx++;
	}
	if (str[idx] == '\n')
	{
		line[idx] = str[idx];
		idx++;
	}
	line[idx] = '\0';
	return (line);
}

char	*updated_str(char *str)
{
	size_t	idx;
	size_t	remn;
	char	*upd;

	idx = 0;
	while (str[idx] && str[idx] != '\n')
		idx++;
	if (!str[idx])
	{
		free(str);
		return (NULL);
	}
	upd = (char *)malloc(sizeof(char) * (ft_gnl_strlen(str) - idx + 1));
	if (!upd)
		return (NULL);
	idx++;
	remn = 0;
	while (str[idx])
		upd[remn++] = str[idx++];
	upd[remn] = '\0';
	free(str);
	return (upd);
}
