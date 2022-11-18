/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <dpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:56:29 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:48:09 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_manager.h"

void	error_message(char *sms)
{
	write(1, sms, ft_strlen(sms));
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

void	free_all_and_exit(t_sems *sems, t_philo **phil, int size, char *sms)
{
	while (--size)
		free(phil[size]);
	free(phil);
	free(sems);
	error_message(sms);
}
