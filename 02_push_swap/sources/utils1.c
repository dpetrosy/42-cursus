/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:37:43 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:37:44 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "sortings.h"

void	init_stack_b(t_stack *st_b, int **sorted)
{
	st_b->head = NULL;
	st_b->tail = NULL;
	st_b->nodes = 0;
	*sorted = NULL;
}

void	double_sort(int *unordered, int *sorted)
{
	ft_printf("sa\n");
	ft_free(unordered, sorted, "");
}

void	free_list_and_exit(t_stack *stack, int *arrays[], int i)
{
	int		j;
	t_lst	*temp;

	j = -1;
	if (arrays[0] != NULL)
		free(arrays[0]);
	if (arrays[1] != NULL)
		free(arrays[1]);
	while (++j < i)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	error_message("[MALLOC ERROR]: List allocation error!");
}

int	is_sorted(int *unordered, int size)
{
	int	i;

	i = 0;
	if (size < 2)
		ft_free(unordered, NULL, "");
	while (++i < size)
	{
		if (unordered[i] <= unordered[i - 1])
			return (1);
	}
	return (0);
}

void	free_stacks_and_arrays(t_stack *st_a, t_stack *st_b, int *a1, int *a2)
{
	t_lst	*temp;
	int		i;

	i = -1;
	while (++i < st_a->nodes)
	{
		temp = st_a->head;
		st_a->head = st_a->head->next;
		free(temp);
	}
	if (st_b->head != NULL)
	{
		i = -1;
		while (++i < st_a->nodes)
		{
			temp = st_a->head;
			st_a->head = st_a->head->next;
			free(temp);
		}
	}
	if (a1 != NULL)
		free(a1);
	if (a1 != NULL)
		free(a2);
}
