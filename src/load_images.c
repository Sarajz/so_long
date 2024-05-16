/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:28:11 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/16 17:01:46 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_game *game)
{
	int	len;

	len = 64;
	game->img.wall = mlx_texture_to_image(game->mlx, game->t.wall);
	game->img.floor = mlx_texture_to_image(game->mlx, game->t.floor);
	game->img.player = mlx_texture_to_image(game->mlx, game->t.player);
	game->img.collectible = mlx_texture_to_image(game->mlx,
			game->t.collectible);
	game->img.exit = mlx_texture_to_image(game->mlx, game->t.exit);
}

int	load_texture_n_image(t_game *game)
{
	game->t.wall = mlx_load_png("./images/wall.png");
	if (!game->t.wall)
		return (1);
	game->t.floor = mlx_load_png("./images/floor.png");
	if (!game->t.floor)
		return (1);
	game->t.player = mlx_load_png("./images/player.png");
	if (!game->t.player)
		return (1);
	game->t.collectible = mlx_load_png("./images/collectible.png");
	if (!game->t.collectible)
		return (1);
	game->t.exit = mlx_load_png("./images/exit.png");
	if (!game->t.exit)
		return (1);
	load_image(game);
	return (0);
}

void	draw_map(int i, int j, char c, t_game *game)
{
	mlx_image_to_window(game->mlx, game->img.floor, W_WIDTH * i, W_HEIGHT * j);
	if (c == '1')
		mlx_image_to_window(game->mlx, game->img.wall,
			W_WIDTH * i, W_HEIGHT * j);
	if (c == 'P')
		mlx_image_to_window(game->mlx, game->img.player,
			W_WIDTH * i, W_HEIGHT * j);
	if (c == 'C')
		mlx_image_to_window(game->mlx, game->img.collectible,
			W_WIDTH * i, W_HEIGHT * j);
	if (c == 'E')
		mlx_image_to_window(game->mlx, game->img.exit,
			W_WIDTH * i, W_HEIGHT * j);
}

void	check_matrix(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			draw_map (j, i, game->map[i][j], game);
			j++;
		}
		i++;
	}
}
