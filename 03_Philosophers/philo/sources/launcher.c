/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:57:35 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/10/29 19:51:41 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "launcher.h"
#include "error_manager.h"
#include "utils.h"

void	control(t_philo **philos, t_mutex *mutexes, int count, t_id th_id)
{
	int	i;

	if (creat_th(philos, mutexes, count, th_id) == 1)
		return ;
	i = -1;
	while (++i != -2)
	{
		pthread_mutex_lock(&mutexes[count]);
		if (get_current_time() - philos[i]->last_eat > philos[i]->times.die)
		{
			pthread_mutex_unlock(&mutexes[count + 2]);
			print_action(philos[i], RED" died"RESET);
			pthread_mutex_unlock(&mutexes[count + 2]);
			break ;
		}
		pthread_mutex_unlock(&mutexes[count]);
		pthread_mutex_lock(&mutexes[count + 1]);
		if (philos[0]->times.must_eat != -1)
			if (check_eat(philos, count) == 1)
				break ;
		pthread_mutex_unlock(&mutexes[count + 1]);
		if (i == count - 1)
			i = -1;
	}
}

int	creat_th(t_philo **philos, t_mutex *mutexes, int count, t_id th_id)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (pthread_create(&th_id, NULL, launcher, philos[i]) != 0)
		{
			free_all_and_exit(mutexes, philos, count, "[THREAD CREAT ERROR]");
			return (1);
		}
		if (pthread_detach(th_id) != 0)
		{
			free_all_and_exit(mutexes, philos, count, "[THREAD DETACH ERROR]");
			return (1);
		}
	}
	return (0);
}

void	*launcher(void *tmp)
{
	t_philo	*philo;

	philo = tmp;
	pthread_mutex_lock(&(philo->mutexes[philo->count]));
	philo->last_eat = get_current_time();
	pthread_mutex_unlock(&(philo->mutexes[philo->count]));
	if (philo->philo_num % 2 == 0)
		usleep(50);
	pthread_mutex_lock(&(philo->mutexes[philo->count + 3]));
	philo->born = get_current_time();
	pthread_mutex_unlock(&(philo->mutexes[philo->count + 3]));
	while (1)
	{
		live(philo);
	}
	return (NULL);
}

void	live(t_philo *philo)
{	
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, " has taken a fork");
	print_action(philo, " is eating");
	pthread_mutex_lock(&(philo->mutexes[philo->count]));
	philo->last_eat = get_current_time();
	pthread_mutex_unlock(&(philo->mutexes[philo->count]));
	pthread_mutex_lock(&(philo->mutexes[philo->count + 1]));
	philo->eat_count += 1;
	pthread_mutex_unlock(&(philo->mutexes[philo->count + 1]));
	my_sleep(philo->times.eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_action(philo, " is sleeping");
	my_sleep(philo->times.sleep);
	print_action(philo, " is thinking");
}

int	check_eat(t_philo **philos, int count)
{
	int		i;
	int		eat_count;

	i = -1;
	eat_count = 0;
	while (++i < count)
	{
		if (philos[i]->eat_count >= philos[i]->times.must_eat)
			eat_count += philos[i]->times.must_eat;
	}
	if (eat_count == count * philos[0]->times.must_eat)
		return (1);
	return (0);
}
