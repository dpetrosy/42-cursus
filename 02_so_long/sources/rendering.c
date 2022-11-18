/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:11:58 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:12:01 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#ifdef __linux__
# define SWITCH	2000
#else
# define SWITCH 55
#endif

void	get_imgs(t_engine *game, t_imgs *imgs)
{	
	int	width;
	int	height;

	imgs->p_1 = mlx_xpm_file_to_image(game->mlx, PLAYER_1, &width, &height);
	imgs->p_2 = mlx_xpm_file_to_image(game->mlx, PLAYER_2, &width, &height);
	imgs->coin_1 = mlx_xpm_file_to_image(game->mlx, COIN_1, &width, &height);
	imgs->coin_2 = mlx_xpm_file_to_image(game->mlx, COIN_2, &width, &height);
	imgs->enemy_1 = mlx_xpm_file_to_image(game->mlx, ENEMY_1, &width, &height);
	imgs->enemy_2 = mlx_xpm_file_to_image(game->mlx, ENEMY_2, &width, &height);
	imgs->wall = mlx_xpm_file_to_image(game->mlx, WALL, &width, &height);
	imgs->e_close = mlx_xpm_file_to_image(game->mlx,
			EXIT_CLOSED, &width, &height);
	imgs->e_open = mlx_xpm_file_to_image(game->mlx,
			EXIT_OPEN, &width, &height);
	imgs->bg = mlx_xpm_file_to_image(game->mlx, BACKGROUND, &width, &height);
	imgs->moves = mlx_xpm_file_to_image(game->mlx, MOVES_PATH, &width, &height);
}

int	render_next_frame(t_engine *game)
{
	render(game);
	mlx_do_sync(game->mlx);
	return (0);
}

void	render(t_engine *game)
{
	int			i;
	int			j;
	int			arr[2];
	static int	switcher;

	if (switcher >= SWITCH)
		switcher = 0;
	++switcher;
	i = -1;
	while (game->map.map_[++i])
	{
		j = -1;
		while (game->map.map_[i][++j])
		{
			arr[0] = i * IMG_SIZE;
			arr[1] = j * IMG_SIZE;
			put_img(arr, game->map.map_[i][j], game, &switcher);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->imgs.moves, 1, i * IMG_SIZE);
	print_moves(game);
}

void	put_img(int *arr, char symbol, t_engine *game, int *switcher)
{
	int	i;
	int	j;

	i = arr[0];
	j = arr[1];
	if (symbol == Wall)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall, j, i);
	else if (symbol == Empty)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.bg, j, i);
	else if (symbol == Coin && *switcher < SWITCH / 2)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.coin_1, j, i);
	else if (symbol == Coin && *switcher < SWITCH)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.coin_2, j, i);
	else if (symbol == Enemy && *switcher < SWITCH / 2)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.enemy_1, j, i);
	else if (symbol == Enemy && *switcher < SWITCH)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.enemy_2, j, i);
	else if (symbol == Exit && game->map.coin == game->c_collect)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.e_open, j, i);
	else if (symbol == Exit)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.e_close, j, i);
	else if (symbol == Player && *switcher < SWITCH / 2)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.p_1, j, i);
	else if (symbol == Player && *switcher < SWITCH)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.p_2, j, i);
}

void	print_moves(t_engine *game)
{
	char	*moves;
	char	*temp;

	temp = ft_itoa(game->moves);
	moves = ft_strjoin("Move Count: ", temp);
	free(temp);
	mlx_string_put(game->mlx, game->win,
		15, game->map.height * IMG_SIZE + MOVES / 1.2, WHITE_FONT, moves);
	free(moves);
}
