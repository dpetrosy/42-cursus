/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:40:24 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:40:26 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_STACK_BONUS_H
# define MAKE_STACK_BONUS_H

# include "push_swap_bonus.h"

int		*get_nums(int nums_count, char **argv);
void	make_stack_a(t_stack *stack, int *unordered, int size);
t_lst	*make_lst(t_stack *stack, int *unordered, int i);

#endif   /* MAKE_STACK_BONUS_H */
