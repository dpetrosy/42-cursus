/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:12:06 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:12:08 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "so_long.h"
#include "map_utils.h"

void	args_valid(int argc, char **argv)
{
	int		fd;
	char	*ext;
	int		len;

	if (argc != 2)
		error_message("[ARGUMENTS ERROR]: Wrong count of arguments!");
	len = ft_strlen(argv[1]);
	if (len < 5)
		error_message("[FILE NAME ERROR]: Wrong file name");
	ext = ft_substr(argv[1], len - 4, 4);
	if (ft_strncmp(ext, ".ber", 5) != 0)
		error_message("[FILE NAME ERROR]: File extension must be \".ber\"!");
	free(ext);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_message("[FILE ACCESS ERROR]: Can't open file!");
	close(fd);
}

void	error_message(char *sms)
{
	ft_printf("%s\n", sms);
	exit(EXIT_FAILURE);
}

void	get_player_coords(t_engine *game)
{
	int	i;
	int	j;

	game->coords.i = -1;
	game->coords.j = -1;
	i = -1;
	while (game->map.map_[++i])
	{
		j = -1;
		while (game->map.map_[i][++j])
		{
			if (game->map.map_[i][j] == Player)
			{
				game->coords.i = i;
				game->coords.j = j;
				break ;
			}
		}
		if (game->coords.i != -1)
			break ;
	}
}

void	close_window_free_and_exit(t_engine *game, char *sms)
{
	mlx_destroy_window(game->mlx, game->win);
	map_free(game->map.height, &game->map);
	ft_printf("You did %d moves\n", game->moves);
	error_message(sms);
}

int	on_destroy_exit(t_engine *game)
{
	mlx_destroy_window(game->mlx, game->win);
	map_free(game->map.height, &game->map);
	ft_printf("You left the game and did %d moves\n", game->moves);
	exit(EXIT_SUCCESS);
}
