/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:09:51 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/04/23 00:13:21 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*ret_line;
	int			i;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer[fd] = get_joined_buffer(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	i = 0;
	while (buffer[fd][i] != '\n' && buffer[fd][i] != '\0')
		++i;
	if (buffer[fd][i] == '\n')
		++i;
	ret_line = ft_substr(buffer[fd], 0, i);
	temp = ft_substr(buffer[fd], i, ft_strlen(buffer[fd]) - (i));
	free(buffer[fd]);
	buffer[fd] = temp;
	return (ret_line);
}

char	*get_joined_buffer(char *buffer, int fd)
{
	char	temp[BUFFER_SIZE + 1];
	int		i;

	temp[BUFFER_SIZE] = '\0';
	i = -1;
	while (++i < BUFFER_SIZE)
		temp[i] = '\0';
	i = 1;
	while (!ft_strchr(temp, '\n') && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0 || (i == 0 && !buffer))
			return (NULL);
		temp[i] = '\0';
		if (!buffer)
			buffer = ft_strdup(temp);
		else
			buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}
