/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <dpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:50:59 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:37:45 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/wait.h>
# include "libft.h"
# include "colors.h"

typedef pthread_t		t_id;
typedef struct timeval	t_timeval;

typedef struct s_times
{
	int	die;
	int	eat;
	int	sleep;
	int	must_eat;
}	t_times;

typedef struct s_sems
{
	sem_t	*forks;
	sem_t	*print;
	sem_t	*die;
	sem_t	*must_eat;
}	t_sems;

typedef struct s_philo
{
	t_times		times;
	t_sems		*sems;
	long long	last_eat;
	long long	born;
	int			philo_num;
	int			eat_count;
	int			count;
}	t_philo;

typedef struct s_arguments {
	t_philo	**philos;
	pid_t	*ids;
	int		count;
}	t_arguments;

#endif   /* PHILO_H */
