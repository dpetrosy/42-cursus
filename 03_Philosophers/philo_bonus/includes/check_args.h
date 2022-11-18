/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:50:04 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:43:52 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGS_H
# define CHECK_ARGS_H

# include "philo.h"

int	check_args(int argc, char **argv);
int	get_nums_count(char **argv, char ***temp);
int	check_num(char *num, int *nums_count);
int	check_num1(char *num);
int	check_split_len(char **temp);

#endif   /* CHECK_ARGS_H */
