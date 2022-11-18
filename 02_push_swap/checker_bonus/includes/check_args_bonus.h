/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:39:46 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/23 19:40:04 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGS_BONUS_H
# define CHECK_ARGS_BONUS_H

# include "push_swap_bonus.h"

int		check_args(int argc, char **argv);
int		get_nums_count(char **argv);
void	check_num(char *num, char **temp, int *nums_count);
void	check_num1(char *num, char **temp);
void	check_duplicates(int *unordered, int size);

#endif   /* CHECK_ARGS_BONUS_H */
