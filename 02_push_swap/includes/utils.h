/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:39:16 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:39:17 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "push_swap.h"

void	init_stack_b(t_stack *st_b, int **sorted);
void	error_message(char *sms);
void	free_matrix(char **matrix, int size);
int		get_matrix_size(char **matrix);
void	free_and_exit(char **matrix, int size, char *sms);
void	ft_free(int *unordered, int *sorted, char *sms);
void	free_list_and_exit(t_stack *stack, int *arrays[], int i);
int		is_sorted(int *unordered, int size);
void	free_stacks_and_arrays(t_stack *st_a, t_stack *st_b, int *a1, int *a2);

#endif   /* UTILS_H */
