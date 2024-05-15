/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:33:47 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/15 16:34:26 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(t_game *game)
{
	for (int i = 0; game->map[i]; i++)
		printf("%s\n", game->map[i]);
	printf("Huesitos: %d\n", game->count_collect);
	printf("Salida: %d, %d\n", game->exit_x, game->exit_y);
}

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
	if (keycode.key == MLX_KEY_E && keycode.action == MLX_PRESS)
		print_map(game);
}

void	print_moves(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = game->player_x;
	py = game->player_y;
	if (game->map[py + y][px + x] == '0')
		game->move++;
	
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init(W_WIDTH * game->col, W_HEIGHT * game->line, "so_long" , false);
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
