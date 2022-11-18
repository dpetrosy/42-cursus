/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:11:50 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:11:53 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"
#include "utils.h"
#include "so_long.h"

void	map_free(int i, t_map *map)
{
	while (i >= 0)
	{
		free(map->map_[i]);
		--i;
	}
	free(map->map_);
}

void	check_map_walls(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
		if (map->map_[0][i] != Wall ||
				map->map_[map->height - 1][i] != Wall)
			error_message("[MAP ERROR]: Incorrect walls!");
	i = -1;
	while (++i < map->height)
		if (map->map_[i][0] != Wall ||
				map->map_[i][map->width - 1] != Wall)
			error_message("[MAP ERROR]: Incorrect walls!");
}

void	print_map(t_engine *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.map_[++i])
	{
		j = -1;
		while (game->map.map_[i][++j])
			ft_printf("%c", game->map.map_[i][j]);
		ft_printf("\n");
	}
}
