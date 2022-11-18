/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:11:10 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:11:12 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils.h"
#include "map_parser.h"
#include "game.h"
#include "map_utils.h"
#include "rendering.h"

int	main(int argc, char **argv)
{
	t_engine	game;

	init_game(argc, argv, &game);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		map_free(game.map.height, &game.map);
		error_message("[MLX ERROR]: can't do mlx_init!");
	}
	get_imgs(&game, &game.imgs);
	game.win = mlx_new_window(game.mlx, game.map.width * IMG_SIZE,
			game.map.height * IMG_SIZE + MOVES, "I LOVE MLX LEAKS");
	if (!game.win)
	{
		map_free(game.map.height, &game.map);
		error_message("[MLX ERROR]: can't open mlx window!");
	}
	mlx_key_hook(game.win, move_player, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_hook(game.win, 17, 0, on_destroy_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}

void	init_game(int argc, char **argv, t_engine *game)
{
	if (argc < 2)
	{
		display_info();
		exit(EXIT_FAILURE);
	}
	game->moves = 0;
	game->c_collect = 0;
	args_valid(argc, argv);
	game->map = parse_map(argv[1]);
	get_player_coords(game);
}

void	display_info(void)
{
	char	*sms;

	sms = "\tThis INTERSETING game is developed by gverdyan and dpetrosy\
 for kids.\n\tYou need to collect all jelyfishes to finish the \
game.\n\tWhen you did so, the pineapple becomes the House where\
 you can escape from evil you!\n\tTo start the game identify\
the map. Be Careful it is so hard and your life depends on it.\
	\n\tOnly 0.13\% can handle this challenge.\
	\n\tGood luck, Bikkini Bottom relies on you.\
	\n\n\tP.S. We love 42 norminette and 42 minilibx leaks";
	ft_printf("%si\n", sms);
}
