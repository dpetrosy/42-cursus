/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:10:35 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:10:38 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map_utils.h"
#include "utils.h"
#include "so_long.h"

int	move_player(int key, t_engine *game)
{
	if (key == Up || key == Up_arrow)
		move(game, -1, 0);
	else if (key == Down || key == Down_arrow)
		move(game, 1, 0);
	else if (key == Right || key == Right_arrow)
		move(game, 0, 1);
	else if (key == Left || key == Left_arrow)
		move(game, 0, -1);
	else if (key == Esc || key == Quit)
		close_window_free_and_exit(game, "Game left!");
	return (0);
}

void	move(t_engine *game, int i, int j)
{
	if (game->map.map_[game->coords.i + i][game->coords.j + j] == Enemy)
	{
		game->moves++;
		close_window_free_and_exit(game, "GAME OVER! Enemy cought you!");
	}
	else if (game->map.map_[game->coords.i + i][game->coords.j + j] == Coin)
	{
		game->moves++;
		game->c_collect++;
		game->map.map_[game->coords.i + i][game->coords.j + j] = Player;
		game->map.map_[game->coords.i][game->coords.j] = Empty;
		game->coords.i += i;
		game->coords.j += j;
	}
	else
		move_continue(game, i, j);
}

void	move_continue(t_engine *game, int i, int j)
{
	if (game->map.map_[game->coords.i + i][game->coords.j + j] == Exit)
	{
		if (game->c_collect == game->map.coin)
		{
			game->moves++;
			game->map.map_[game->coords.i + i][game->coords.j + j] = Player;
			game->map.map_[game->coords.i][game->coords.j] = Empty;
			game->coords.i += i;
			game->coords.j += j;
			close_window_free_and_exit(game,
				"You have passed this DIFFICULT game! CONGRATS");
		}
	}
	else if (game->map.map_[game->coords.i + i][game->coords.j + j] == Empty)
	{
		game->moves++;
		game->map.map_[game->coords.i + i][game->coords.j + j] = Player;
		game->map.map_[game->coords.i][game->coords.j] = Empty;
		game->coords.i += i;
		game->coords.j += j;
	}
}
