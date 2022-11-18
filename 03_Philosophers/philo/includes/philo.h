/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:50:59 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/29 17:52:36 by dpetrosy         ###   ########.fr       */
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
# include "libft.h"
# include "colors.h"

typedef pthread_t		t_id;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_times
{
	int	die;
	int	eat;
	int	sleep;
	int	must_eat;
}	t_times;

typedef struct s_philo
{
	t_times		times;
	long long	last_eat;
	long long	born;
	int			philo_num;
	int			eat_count;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		*mutexes;
	int			count;
}	t_philo;

#endif   /* PHILO_H */
