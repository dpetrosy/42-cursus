/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:59:17 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/10/29 19:51:58 by dpetrosy         ###   ########.fr       */
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
	pthread_mutex_lock(&(philo->mutexes[philo->count + 3]));
	printf(GREEN"[%lld]"RESET" %d%s\n",
		get_current_time() - philo->born, philo->philo_num, action);
	pthread_mutex_unlock(&(philo->mutexes[philo->count + 3]));
}

void	my_sleep(int mls)
{
	long long	start;

	start = get_current_time();
	while (get_current_time() - start < mls)
		usleep(100);
}

void	destroy_all(t_mutex *mutexes, t_philo **philos, int count)
{
	int	i;

	i = -1;
	count += 4;
	while (++i < count)
		pthread_mutex_destroy(&mutexes[i]);
	free_all_and_exit(mutexes, philos, count - 4, "");
}
