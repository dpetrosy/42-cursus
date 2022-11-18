/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:09:50 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:09:52 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include "so_long.h"

void	map_free(int i, t_map *map);
void	check_map_walls(t_map *map);
void	print_map(t_engine *map);

#endif	/* MAP_UTILS_H */
