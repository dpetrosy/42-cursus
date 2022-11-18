/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <dpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:50:37 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:37:47 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCHER_H
# define LAUNCHER_H

void	control(t_philo **philos, pid_t *ids, int count);
void	launcher(void *tmp);
void	live(t_philo *philo);
void	*check_die(void	*tmp);
void	*check_must_eat(void *params);

#endif   /* LAUNCHER_H */
