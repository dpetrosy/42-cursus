/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:42:55 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:42:58 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_actions_bonus.h"
#include "utils_bonus.h"

void	swap_stack(t_stack *stack)
{
	int	temp;

	if (stack->nodes <= 1)
		return ;
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
}

void	rotate_stack(t_stack *stack)
{
	if (stack->nodes <= 1)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	reverse_rotate_stack(t_stack *stack)
{
	if (stack->nodes <= 1)
		return ;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	push_stack(t_stack *from, t_stack *to)
{
	t_lst	*new_lst;

	if (from->head == NULL)
		return ;
	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		error_message("[MALLOC ERROR]: dynamic memory allocation error!");
	++to->nodes;
	new_lst->value = from->head->value;
	if (to->head == NULL)
	{
		new_lst->next = NULL;
		new_lst->prev = NULL;
		to->head = new_lst;
		to->tail = new_lst;
	}
	else
	{
		new_lst->next = to->head;
		new_lst->prev = to->tail;
		to->head->prev = new_lst;
		to->head = new_lst;
		to->tail->next = to->head;
	}
	push_stack_2(from);
}

void	push_stack_2(t_stack *from)
{
	if (from->nodes == 1)
	{	
		free(from->head);
		from->head = NULL;
		from->tail = NULL;
	}
	else if (from->nodes == 2)
	{
		from->tail->next = NULL;
		from->tail->prev = NULL;
		free(from->head);
		from->head = from->tail;
	}
	else
	{
		from->head->next->prev = from->tail;
		from->tail->next = from->head->next;
		free(from->head);
		from->head = from->tail->next;
	}
	--from->nodes;
}
