/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:10:20 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:10:22 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <fcntl.h>
# include <stdio.h>
# include "so_long.h"

void	init_game(int argc, char **argv, t_engine *game);
void	display_info(void);
void	error_message(char *sms);
void	args_valid(int argc, char **argv);
void	get_player_coords(t_engine *game);
void	close_window_free_and_exit(t_engine *game, char *sms);
int		on_destroy_exit(t_engine *game);

#endif	/* UTILS_H */
