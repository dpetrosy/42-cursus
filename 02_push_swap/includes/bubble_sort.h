/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:38:09 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:38:12 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUBBLE_SORT_H
# define BUBBLE_SORT_H

# include "ft_printf.h"
# include "push_swap.h"

void	swap(int *a, int *b);
void	bubble_sort(int *arr, int size);
void	print_array(int *arr, int size);
int		*copy_into_sorted(int *arr, int size);
int		*get_nums(int nums_count, char **argv);

#endif   /* BUBBLE_SORT_H */
