/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:43:26 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:43:27 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	error_message(char *sms)
{
	write(2, sms, ft_strlen(sms));
	exit(EXIT_FAILURE);
}

void	free_matrix(char **matrix, int size)
{
	size = size - 1;
	while (size >= 0)
	{
		free(matrix[size]);
		--size;
	}
	free(matrix);
}

int	get_matrix_size(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		;
	return (i + 1);
}

void	free_and_exit(char **matrix, int size, char *sms)
{
	free_matrix(matrix, size);
	error_message(sms);
}

void	ft_free(int *unordered, int *sorted, char *sms)
{
	if (unordered != NULL)
		free(unordered);
	if (sorted != NULL)
		free(sorted);
	error_message(sms);
}
