/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:50:37 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/29 17:50:38 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCHER_H
# define LAUNCHER_H

void	control(t_philo **philos, t_mutex *mutexes, int count, t_id th_id);
int		creat_th(t_philo **philos, t_mutex *mutexes, int count, t_id th_id);
void	*launcher(void *tmp);
void	live(t_philo *philo);
int		check_eat(t_philo **philos, int count);

#endif   /* LAUNCHER_H */
