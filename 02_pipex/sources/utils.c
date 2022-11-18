/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:39:03 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/17 22:39:07 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	i = 0;
	if (!needle[i] || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && i + j < len
			&& haystack[i + j] == needle[j])
			j++;
		if (j == len_needle)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}

void	free_exec(char *operand, char **paths)
{
	int	i;

	i = -1;
	free(operand);
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

void	garbage_collector(t_fd *fds, int **pipes, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		free(pipes[i]);
	free(pipes);
	pipes = NULL;
	if (close(fds->file_in) == -1 || close(fds->file_out) == -1)
		error_message("\n[File Close ERROR]", 0);
}

void	error_message(char const *sms, int mode)
{
	if (mode == 0)
		perror(sms);
	else
		write(1, sms, ft_strlen(sms) + 1);
	exit(EXIT_FAILURE);
}
