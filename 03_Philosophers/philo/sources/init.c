/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:54:41 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/09/03 19:11:18 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_manager.h"
#include "init.h"

t_mutex	*init_mutexes(int philos_count)
{
	t_mutex	*mutexes;

	mutexes = (t_mutex *)malloc(sizeof(t_mutex) * (philos_count + 4));
	if (!mutexes)
		return (NULL);
	philos_count += 5;
	while (--philos_count >= 0)
	{
		if (pthread_mutex_init(&mutexes[philos_count], NULL) != 0)
			return (NULL);
	}
	return (mutexes);
}

t_philo	**init_philos(int argc, char **argv, t_mutex *mutexes, int count)
{
	t_philo	**philos;
	int		arr[2];

	if (count == 0)
		return (NULL);
	philos = (t_philo **)malloc(sizeof(t_philo) * count);
	if (!philos)
		return (NULL);
	arr[0] = argc;
	arr[1] = count;
	for_each(argv, mutexes, philos, arr);
	return (philos);
}

void	for_each(char **argv, t_mutex *mutexes, t_philo **philos, int arr[])
{
	int	i;

	i = -1;
	while (++i < arr[1])
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		philos[i]->times.die = ft_atoi(argv[2]);
		philos[i]->times.eat = ft_atoi(argv[3]);
		philos[i]->times.sleep = ft_atoi(argv[4]);
		if (arr[0] == 6)
			philos[i]->times.must_eat = ft_atoi(argv[5]);
		else
			philos[i]->times.must_eat = -1;
		philos[i]->last_eat = LONG_MAX;
		philos[i]->born = LONG_MAX;
		philos[i]->philo_num = i + 1;
		philos[i]->eat_count = 0;
		philos[i]->mutexes = mutexes;
		philos[i]->count = arr[1];
		if (i == arr[1] - 1)
			philos[i]->left_fork = &mutexes[0];
		else
			philos[i]->left_fork = &mutexes[i + 1];
		philos[i]->right_fork = &mutexes[i];
	}
}
