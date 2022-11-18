/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <dpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:54:41 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:48:09 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_manager.h"
#include "init.h"

t_sems	*init_sems(int count)
{
	t_sems	*sems;

	sems = (t_sems *)malloc(sizeof(t_sems));
	if (!sems)
		return (NULL);
	sems->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, count);
	sem_unlink("forks");
	sems->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("print");
	sems->die = sem_open("die", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("die");
	sems->must_eat = sem_open("must_eat", O_CREAT | O_EXCL, 0644, 0);
	sem_unlink("must_eat");
	if (sems->forks == SEM_FAILED || sems->print == SEM_FAILED)
	{
		free(sems);
		return (NULL);
	}
	return (sems);
}

t_philo	**init_philos(int argc, char **argv, t_sems *sems, int count)
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
	for_each(argv, sems, philos, arr);
	return (philos);
}

void	for_each(char **argv, t_sems *sems, t_philo **philos, int arr[])
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
			philos[i]->times.must_eat = 0;
		philos[i]->last_eat = LONG_MAX;
		philos[i]->born = LONG_MAX;
		philos[i]->philo_num = i + 1;
		philos[i]->eat_count = 0;
		philos[i]->sems = sems;
		philos[i]->count = arr[1];
	}
}
