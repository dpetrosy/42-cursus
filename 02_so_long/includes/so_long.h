/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:10:13 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:10:15 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

// Paths of Images
# define PLAYER_1 "./images/xpm/player_1.xpm"
# define PLAYER_2 "./images/xpm/player_2.xpm"
# define COIN_1 "./images/xpm/coin_1.xpm"
# define COIN_2 "./images/xpm/coin_2.xpm"
# define ENEMY_1 "./images/xpm/enemy_1.xpm"
# define ENEMY_2 "./images/xpm/enemy_2.xpm"
# define WALL  "./images/xpm/wall.xpm"
# define EXIT_OPEN "./images/xpm/exit_open.xpm"
# define EXIT_CLOSED "./images/xpm/exit_closed.xpm"
# define BACKGROUND "./images/xpm/background.xpm"
# define MOVES_PATH "./images/xpm/moves.xpm"

// Features of Images
# define IMG_SIZE 64
# define MOVES 20
# define WHITE_FONT 16777215

# ifdef __linux__

enum e_keys
{
	key_w = 119,
	key_a = 97,
	key_s = 115,
	key_d = 100,
	key_q = 113,
	key_esc = 65307,
	arrow_right = 65363,
	arrow_left = 65361,
	arrow_up = 65362,
	arrow_down = 65364
};

# else

enum e_keys
{
	key_w = 13,
	key_a = 0,
	key_s = 1,
	key_d = 2,
	key_q = 12,
	key_esc = 53,
	arrow_right = 124,
	arrow_left = 123,
	arrow_up = 126,
	arrow_down = 125
};

# endif

typedef struct s_imgs
{
	void	*p_1;
	void	*p_2;
	void	*coin_1;
	void	*coin_2;
	void	*enemy_1;
	void	*enemy_2;
	void	*wall;
	void	*e_open;
	void	*e_close;
	void	*bg;
	void	*moves;
}	t_imgs;

typedef struct s_map
{
	int		width;
	int		height;
	int		player;
	int		exit;
	int		enemy;
	int		coin;
	char	**map_;
}	t_map;

enum e_map_features
{
	Player = 'P',
	Enemy = 'X',
	Exit = 'E',
	Coin = 'C',
	Wall = '1',
	Empty = '0'
};

enum e_move_controls
{
	Left = key_a,
	Right = key_d,
	Up = key_w,
	Down = key_s,
	Esc = key_esc,
	Quit = key_q,
	Left_arrow = arrow_left,
	Right_arrow = arrow_right,
	Up_arrow = arrow_up,
	Down_arrow = arrow_down
};

typedef struct s_coordinates
{
	int	i;
	int	j;
}	t_coord;

typedef struct s_engine
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		moves;
	int		c_collect;
	t_coord	coords;
	t_imgs	imgs;
}	t_engine;

#endif  /* SO_LONG_H */
