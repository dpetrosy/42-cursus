/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:41:54 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:41:55 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line_bonus.h"
#include "utils_bonus.h"
#include "stack_actions_bonus.h"

void	checker(t_stack *st_a, t_stack *st_b)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst)
	{
		if (check_inst(inst) == 1)
		{
			free_stacks(st_a, st_b);
			error_message("[INSTRUCTION ERROR]\n");
		}
		do_inst(inst, st_a, st_b);
		if (inst != NULL)
			free(inst);
		inst = get_next_line(0);
	}
	is_sorted_stack(st_a, st_b);
}

int	check_inst(char *inst)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "sb\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "ss\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "pa\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "pb\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "ra\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "rb\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "rr\n", 3) == 0)
		return (0);
	if (ft_strncmp(inst, "rra\n", 4) == 0)
		return (0);
	if (ft_strncmp(inst, "rrb\n", 4) == 0)
		return (0);
	if (ft_strncmp(inst, "rrr\n", 4) == 0)
		return (0);
	return (1);
}

void	do_inst(char *inst, t_stack *st_a, t_stack *st_b)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		swap_stack(st_a);
	else if (ft_strncmp(inst, "sb\n", 3) == 0)
		swap_stack(st_b);
	else if (ft_strncmp(inst, "ss\n", 3) == 0)
		ss_stacks(st_a, st_b);
	else if (ft_strncmp(inst, "pa\n", 3) == 0)
		push_stack(st_b, st_a);
	else if (ft_strncmp(inst, "pb\n", 3) == 0)
		push_stack(st_a, st_b);
	else if (ft_strncmp(inst, "ra\n", 3) == 0)
		rotate_stack(st_a);
	else if (ft_strncmp(inst, "rb\n", 3) == 0)
		rotate_stack(st_b);
	else if (ft_strncmp(inst, "rr\n", 3) == 0)
		rr_stacks(st_a, st_b);
	else if (ft_strncmp(inst, "rra\n", 4) == 0)
		reverse_rotate_stack(st_a);
	else if (ft_strncmp(inst, "rrb\n", 4) == 0)
		reverse_rotate_stack(st_b);
	else if (ft_strncmp(inst, "rrr\n", 4) == 0)
		rrr_stacks(st_a, st_b);
}

void	is_sorted_stack(t_stack *st_a, t_stack *st_b)
{
	t_lst	*temp;

	if (st_b->nodes > 0)
		sorted_exit(st_a, st_b, "KO");
	if (st_a->nodes == 1)
		sorted_exit(st_a, st_b, "OK");
	temp = st_a->head;
	while (temp != st_a->tail)
	{
		if (temp->value >= temp->next->value)
			sorted_exit(st_a, st_b, "KO");
		temp = temp->next;
	}
	sorted_exit(st_a, st_b, "OK");
}

void	sorted_exit(t_stack *st_a, t_stack *st_b, char *sms)
{
	free_stacks(st_a, st_b);
	ft_printf("%s\n", sms);
	exit(EXIT_SUCCESS);
}
