/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:54:23 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/29 17:54:24 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "check_args.h"
#include "init.h"
#include "launcher.h"
#include "error_manager.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_philo	**philos;
	t_mutex	*mutexes;
	int		count;
	t_id	th_id;

	th_id = 0;
	if (check_args(argc, argv) == 1 || check_0(argc, argv) == 1)
		return (0);
	count = ft_atoi(argv[1]);
	mutexes = init_mutexes(count);
	if (!mutexes)
	{
		free_all_and_exit(mutexes, NULL, 0, "[ERROR]\n");
		return (0);
	}
	philos = init_philos(argc, argv, mutexes, count);
	if (!philos)
	{
		free_all_and_exit(mutexes, NULL, 0, "[ERROR]\n");
		return (0);
	}
	control(philos, mutexes, count, th_id);
	destroy_all(mutexes, philos, count);
	return (0);
}
