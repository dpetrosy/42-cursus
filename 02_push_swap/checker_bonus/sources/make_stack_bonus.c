/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:42:31 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:42:32 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_stack_bonus.h"
#include "utils_bonus.h"

int	*get_nums(int nums_count, char **argv)
{
	int		*nums;
	char	**temp;
	int		indx[3];

	indx[0] = 0;
	indx[2] = -1;
	nums = (int *)malloc(sizeof(int) * nums_count);
	if (!nums)
		error_message("[MALLOC ERROR]: Dynamic memory allocation fault!\n");
	while (argv[++indx[0]])
	{
		temp = ft_split(argv[indx[0]], ' ');
		if (!temp)
			error_message("[MALLOC ERROR]: Dynamic memory alloc fault!\n");
		else if (temp[0] == NULL)
			free_matrix(temp, 1);
		else
		{
			indx[1] = -1;
			while (temp[++indx[1]])
				nums[++indx[2]] = ft_atoi(temp[indx[1]]);
			free_matrix(temp, get_matrix_size(temp));
		}
	}
	return (nums);
}

void	make_stack_a(t_stack *stack, int *unordered, int size)
{
	int	i;

	stack->head = NULL;
	stack->tail = NULL;
	stack->head = make_lst(stack, unordered, 0);
	i = 0;
	while (++i < size)
		make_lst(stack, unordered, i);
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->nodes = size;
}

t_lst	*make_lst(t_stack *stack, int *unordered, int i)
{
	t_lst	*new_lst;
	t_lst	*temp_head;

	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		free_list_and_exit(stack, unordered, i);
	if (i == 0)
	{
		new_lst->value = unordered[0];
		new_lst->prev = NULL;
	}
	else
	{
		temp_head = stack->head;
		while (temp_head->next != NULL)
			temp_head = temp_head->next;
		new_lst->value = unordered[i];
		temp_head->next = new_lst;
		new_lst->prev = temp_head;
	}
	stack->tail = new_lst;
	new_lst->next = NULL;
	return (new_lst);
}
