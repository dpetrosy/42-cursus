/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <dpetrosy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:54:23 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/11/18 22:48:08 by dpetrosy         ###   ########.fr       */
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
	t_sems	*sems;
	pid_t	*ids;
	int		count;
	int		i;

	if (check_args(argc, argv) == 1 || check_0(argc, argv) == 1)
		exit(EXIT_FAILURE);
	count = ft_atoi(argv[1]);
	sems = init_sems(count);
	if (!sems)
		free_all_and_exit(NULL, NULL, 0, "[ERROR]\n");
	philos = init_philos(argc, argv, sems, count);
	if (!philos)
		free_all_and_exit(sems, NULL, 0, "[ERROR]\n");
	ids = (pid_t *)malloc(sizeof(pid_t) * count);
	if (!ids)
		free_all_and_exit(sems, philos, count, "[ERROR]\n");
	i = -1;
	while (++i < count)
		ids[i] = INT_MIN;
	control(philos, ids, count);
	return (0);
}
