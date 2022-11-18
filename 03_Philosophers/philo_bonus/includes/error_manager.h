/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:50:17 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:37:50 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGER_H
# define ERROR_MANAGER_H

# include "philo.h"

void	error_message(char *sms);
void	free_matrix(char **matrix, int size);
int		get_matrix_size(char **matrix);
void	free_and_exit(char **matrix, int size, char *sms);
void	free_all_and_exit(t_sems *sems, t_philo **phil, int size, char *sms);

#endif   /* ERROR_MANAGER_H */
