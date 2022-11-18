/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:37:19 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:37:20 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_actions.h"
#include "utils.h"

void	swap_stack(t_stack *stack, char *action)
{
	int	temp;

	ft_printf("%s\n", action);
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	temp = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = temp;
}

void	rotate_stack(t_stack *stack, char *action)
{
	if (stack->nodes <= 1)
		return ;
	ft_printf("%s\n", action);
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	reverse_rotate_stack(t_stack *stack, char *action)
{
	ft_printf("%s\n", action);
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	push_stack(t_stack *from, t_stack *to, char *action)
{
	t_lst	*new_lst;

	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		error_message("[MALLOC ERROR]: dynamic memory allocation error!");
	++to->nodes;
	new_lst->value = from->head->value;
	new_lst->index = from->head->index;
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
	push_stack_2(from, action);
}

void	push_stack_2(t_stack *from, char *action)
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
	ft_printf("%s\n", action);
}
