/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:38:35 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:38:38 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_STACK_H
# define MAKE_STACK_H

# include "push_swap.h"

void	make_stack_a(t_stack *stack, int *unordered, int *sorted, int size);
t_lst	*make_lst(t_stack *stack, int *arrays[], int size, int i);
int		find_index(int *arr, int value, int size);

#endif   /* MAKE_STACK_H */
