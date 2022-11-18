/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:10:04 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/08/22 20:10:07 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "so_long.h"

int		render_next_frame(t_engine *game);
void	get_imgs(t_engine *gmae, t_imgs *imgs);
void	render(t_engine *game);
void	put_img(int *arr, char symbol, t_engine *game, int *switcher);
void	print_moves(t_engine *game);

#endif  /* RENDERING_H */
