/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:47:31 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/13 17:28:36 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Función de movimientos válidos
// Función que mueva el personaje

int	move_player(t_game *game)
{
	
}

int	key(int keycode, t_game *game)
{
	int	col;
	int	line;

	col = game->player_x;
	line = game->player_y;

	if (keycode == A)
		col--;
	else if (keycode == D)
		col++;
	else if (keycode == W)
		line--;
	else if (keycode == S)
		line++;
	else if (keycode == ESC)
		ft_close_window(game); //HACER (MLX)
}
