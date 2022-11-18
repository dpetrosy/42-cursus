/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:09:07 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:09:13 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "so_long.h"

int		move_player(int key, t_engine *game);
void	move(t_engine *game, int x_step, int y_step);
void	move_continue(t_engine *game, int x_step, int y_step);

#endif  /* GAME_h */
