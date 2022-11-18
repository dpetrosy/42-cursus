/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <dpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:57:35 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:48:08 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "launcher.h"
#include "error_manager.h"
#include "utils.h"

void	control(t_philo **philos, pid_t *ids, int count)
{
	pid_t		id;
	int			i;
	t_id		must_eat_id;
	t_arguments	args;

	args.count = count;
	args.ids = ids;
	args.philos = philos;
	i = -1;
	if (philos[0]->times.must_eat > 0)
	{
		pthread_create(&must_eat_id, NULL, check_must_eat, (void *)&args);
		pthread_detach(must_eat_id);
	}
	while (++i < count)
	{
		id = fork();
		ids[i] = id;
		if (id == -1)
			destroy_all(philos, ids, count);
		if (id == 0)
			launcher(philos[i]);
	}
	waitpid(-1, NULL, 0);
	destroy_all(philos, ids, count);
}

void	launcher(void *tmp)
{
	t_philo	*philo;
	t_id	id;

	philo = tmp;
	pthread_create(&id, NULL, check_die, philo);
	philo->last_eat = get_current_time();
	philo->born = get_current_time();
	while (TRUE)
		live(philo);
	exit(0);
}

void	live(t_philo *philo)
{
	sem_wait(philo->sems->forks);
	print_action(philo, "has taken a fork");
	sem_wait(philo->sems->forks);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	philo->last_eat = get_current_time();
	philo->eat_count += 1;
	if (philo->times.must_eat > 0 && philo->eat_count == philo->times.must_eat)
		sem_post(philo->sems->must_eat);
	my_sleep(philo->times.eat);
	sem_post(philo->sems->forks);
	sem_post(philo->sems->forks);
	print_action(philo, "is sleeping");
	my_sleep(philo->times.sleep);
	print_action(philo, "is thinking");
}

void	*check_die(void	*tmp)
{
	t_philo	*philo;

	philo = tmp;
	while (TRUE)
	{
		if (get_current_time() - philo->last_eat > philo->times.die)
		{
			sem_wait(philo->sems->die);
			print_action(philo, RED"died"RESET);
			sem_wait(philo->sems->print);
			sem_post(philo->sems->must_eat);
			exit(0);
		}
	}
	return (NULL);
}

void	*check_must_eat(void *params)
{
	t_arguments	*args;
	int			must_eat_count;

	args = (t_arguments *)params;
	must_eat_count = 0;
	while (TRUE)
	{
		sem_wait(args->philos[0]->sems->must_eat);
		++must_eat_count;
		if (must_eat_count == args->count)
			break ;
	}
	destroy_all(args->philos, args->ids, args->count);
	return (NULL);
}
