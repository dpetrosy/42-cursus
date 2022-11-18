/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:43:19 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:43:20 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	free_stacks(t_stack *st_a, t_stack *st_b)
{
	int		i;
	t_lst	*temp;

	if (st_a->head != NULL)
	{
		i = -1;
		while (++i < st_a->nodes)
		{
			temp = st_a->head;
			st_a->head = st_a->head->next;
			free(temp);
		}
	}
	if (st_b->head != NULL)
	{
		i = -1;
		while (++i < st_b->nodes)
		{
			temp = st_b->head;
			st_b->head = st_b->head->next;
			free(temp);
		}
	}
}
