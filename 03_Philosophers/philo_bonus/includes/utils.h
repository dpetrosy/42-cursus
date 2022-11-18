/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <dpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:53:34 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:37:43 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int			check_0(int argc, char **argv);
long long	get_current_time(void);
void		print_action(t_philo *philo, char *action);
void		my_sleep(int microsec);
void		destroy_all(t_philo **philos, pid_t *ids, int count);

#endif   /* UTILS_H */
