/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:37:07 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:37:08 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortings.h"
#include "utils.h"
#include "stack_actions.h"

void	forbbiden_sorting(int size, t_stack *stack_a, t_stack *stack_b)
{
	if (size == 3)
		triple_sort(stack_a);
	else if (size == 4)
		fourple_sort(stack_a, stack_b, size);
	else
		fiveple_sort(stack_a, stack_b, size);
}

void	triple_sort(t_stack *stack_a)
{
	int	arr[3];

	arr[0] = stack_a->head->index;
	arr[1] = stack_a->head->next->index;
	arr[2] = stack_a->head->next->next->index;
	if (arr[0] == 0 && arr[1] == 2)
	{
		reverse_rotate_stack(stack_a, "rra");
		swap_stack(stack_a, "sa");
	}
	else if (arr[0] == 0 && arr[1] == 1)
		return ;
	else if (arr[0] == 1 && arr[1] == 0)
		swap_stack(stack_a, "sa");
	else if (arr[0] == 1 && arr[1] == 2)
		reverse_rotate_stack(stack_a, "rra");
	else if (arr[0] == 2 && arr[1] == 0)
		rotate_stack(stack_a, "ra");
	else if (arr[0] == 2 && arr[1] == 1)
	{
		swap_stack(stack_a, "sa");
		reverse_rotate_stack(stack_a, "rra");
	}
}

void	fourple_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_lst	*lst;

	lst = stack_a->head;
	find_max_and_push_b(lst, stack_a, size);
	push_stack(stack_a, stack_b, "pb");
	triple_sort(stack_a);
	push_stack(stack_b, stack_a, "pa");
	rotate_stack(stack_a, "ra");
}

void	fiveple_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_lst	*lst;

	lst = stack_a->head;
	find_max_and_push_b(lst, stack_a, size);
	push_stack(stack_a, stack_b, "pb");
	lst = stack_a->head;
	find_max_and_push_b(lst, stack_a, size - 1);
	push_stack(stack_a, stack_b, "pb");
	triple_sort(stack_a);
	push_stack(stack_b, stack_a, "pa");
	rotate_stack(stack_a, "ra");
	push_stack(stack_b, stack_a, "pa");
	rotate_stack(stack_a, "ra");
}

void	find_max_and_push_b(t_lst *lst, t_stack *stack_a, int size)
{
	int	i;
	int	is_tail;

	i = 0;
	is_tail = 0;
	while (is_tail == 0)
	{
		if (lst->index == size - 1)
		{
			if (i > size - i - 1)
			{
				while (i++ != size)
					reverse_rotate_stack(stack_a, "rra");
			}
			else
				while (i-- > 0)
					rotate_stack(stack_a, "ra");
			break ;
		}
		++i;
		lst = lst->next;
		if (lst == stack_a->head)
			is_tail = 1;
	}
}
