/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:11:20 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:11:22 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "map_utils.h"
#include "so_long.h"
#include "utils.h"

t_map	parse_map(char *map_name)
{
	t_map	map;

	map = get_map_size(map_name);
	map.player = 0;
	map.exit = 0;
	map.enemy = 0;
	map.coin = 0;
	get_map(&map, map_name);
	check_map_walls(&map);
	get_map_features(&map);
	check_map_features(&map);
	return (map);
}

t_map	get_map_size(char *map_name)
{
	int			fd;
	t_map		map;
	char		*temp;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_message("[FILE ACCESS ERROR]: Can't open file!");
	temp = get_next_line(fd);
	map.width = ft_strlen(temp) - 1;
	map.height = 0;
	while (temp)
	{
		free(temp);
		++map.height;
		temp = get_next_line(fd);
		if (((int)ft_strlen(temp) - 1) != map.width && temp)
			error_message("[MAP ERROR]: Map is not shape of rectangle!");
	}
	free(temp);
	close(fd);
	if (map.width * map.height < 15 || map.height < 3 || map.width < 3)
		error_message("[MAP ERROR]: Map is with wrong size parameters!");
	map.map_ = NULL;
	return (map);
}

void	get_map(t_map *map, char *map_name)
{
	int	fd;
	int	i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_message("[FILE ACCESS ERROR]: Can't open file!");
	map->map_ = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map_)
		error_message("[MALLOC ERROR]: Dynamic memory allocation fault!");
	i = -1;
	while (++i < map->height)
	{
		map->map_[i] = get_next_line(fd);
		if (!map->map_[i])
		{
			map_free(i - 1, map);
			error_message("[MALLOC ERROR]: Dynamic memory allocation fault!");
		}
		map->map_[i][map->width] = '\0';
	}
	map->map_[i] = NULL;
	close(fd);
}

void	get_map_features(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_[++i])
	{
		j = -1;
		while (map->map_[i][++j])
		{
			if (map->map_[i][j] == Player)
				map->player++;
			else if (map->map_[i][j] == Exit)
				map->exit++;
			else if (map->map_[i][j] == Enemy)
				map->enemy++;
			else if (map->map_[i][j] == Coin)
				map->coin++;
		}
	}
}

void	check_map_features(t_map *map)
{
	if (map->player != 1)
		error_message("[MAP ERROR]: Players in map must be only 1");
	if (map->exit < 1)
		error_message("[MAP ERROR]: In map must be at least 1 exit!");
	if (map->coin < 1)
		error_message("[MAP ERROR]: In map must be at least 1 money!");
}
