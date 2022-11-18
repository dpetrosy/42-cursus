/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:39:57 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:39:59 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap_bonus.h"

void	checker(t_stack *st_a, t_stack *st_b);
int		check_inst(char *inst);
void	do_inst(char *inst, t_stack *st_a, t_stack *st_b);
void	is_sorted_stack(t_stack *st_a, t_stack *st_b);
void	sorted_exit(t_stack *st_a, t_stack *st_b, char *sms);

#endif	/* CHECKER_BONUS_H */
