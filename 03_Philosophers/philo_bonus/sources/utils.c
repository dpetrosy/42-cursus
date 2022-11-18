/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <dpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:59:17 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:48:05 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "error_manager.h"

int	check_0(int argc, char **argv)
{
	while (--argc > 0)
	{
		if (ft_atoi(argv[argc]) == 0)
		{
			error_message("[ARGUMENT ERROR]\n");
			return (1);
		}
	}
	return (0);
}

long long	get_current_time(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_action(t_philo *philo, char *action)
{
	sem_wait(philo->sems->print);
	printf(GREEN"[%lld]"RESET" %d %s\n",
		get_current_time() - philo->born, philo->philo_num, action);
	sem_post(philo->sems->print);
}

void	my_sleep(int mls)
{
	long long	start;

	start = get_current_time();
	while (get_current_time() - start < mls)
		usleep(100);
}

void	destroy_all(t_philo **philos, pid_t *ids, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ids[i] == -1)
		{
			++i;
			continue ;
		}
		kill(ids[i], SIGKILL);
		++i;
	}
	sem_close(philos[0]->sems->forks);
	sem_close(philos[0]->sems->print);
	sem_close(philos[0]->sems->die);
	free(ids);
	free_all_and_exit(philos[0]->sems, philos, count, "");
}
