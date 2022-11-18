/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:53:12 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:37:49 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo.h"

t_sems	*init_sems(int count);
t_philo	**init_philos(int argc, char **argv, t_sems *sems, int count);
void	for_each(char **argv, t_sems *sems, t_philo **philos, int arr[]);

#endif   /* INIT_H */
