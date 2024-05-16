/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:33:47 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/16 16:48:45 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_key(mlx_key_data_t keycode, void *param)
{
	t_game	*game;

	game = param;
	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keycode.key == MLX_KEY_A && keycode.action == MLX_PRESS)
		move_player(game, -1, 0);
	if (keycode.key == MLX_KEY_D && keycode.action == MLX_PRESS)
		move_player(game, +1, 0);
	if (keycode.key == MLX_KEY_W && keycode.action == MLX_PRESS)
		move_player(game, 0, -1);
	if (keycode.key == MLX_KEY_S && keycode.action == MLX_PRESS)
		move_player(game, 0, +1);
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init(W_WIDTH * game->col,
			W_HEIGHT * game->line, "so_long", false);
	if (!game->mlx)
		return (ft_exit("No mlx"));
	if (load_texture_n_image(game))
		return (1);
	check_matrix(game);
	mlx_key_hook(game->mlx, &press_key, game);
	mlx_loop(game->mlx);
	mlx_delete_texture(game->t.wall);
	mlx_delete_texture(game->t.floor);
	mlx_delete_texture(game->t.player);
	mlx_delete_texture(game->t.collectible);
	mlx_delete_texture(game->t.exit);
	mlx_terminate(game->mlx);
	return (0);
}
