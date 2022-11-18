/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:09:41 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:09:44 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include "so_long.h"

t_map	parse_map(char *map_name);
t_map	get_map_size(char *map_name);
void	get_map(t_map *map, char *map_name);
void	get_map_features(t_map *map);
void	check_map_features(t_map *map);

#endif	/* MAP_PARSER_H */
