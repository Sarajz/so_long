/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:47:31 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/16 17:00:25 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_no_win(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = game->player_x;
	py = game->player_y;
	game->map[py][px] = '0';
	game->map[py + y][px + x] = 'P';
	game->player_x = game->player_x + x;
	game->player_y = game->player_y + y;
	mlx_image_to_window(game->mlx, game->img.exit,
		W_WIDTH * game->player_x, W_HEIGHT * game->player_y);
	mlx_image_to_window(game->mlx, game->img.player,
		W_WIDTH * game->player_x, W_HEIGHT * game->player_y);
	draw_map(px, py, '0', game);
}

void	take_collectible(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = game->player_x;
	py = game->player_y;
	if (py == game->exit_y && px == game->exit_x)
	{
		game->map[py][px] = 'E';
		game->map[py + y][px + x] = 'P';
		game->player_x = game->player_x + x;
		game->player_y = game->player_y + y;
		draw_map(game->player_x, game->player_y, 'P', game);
		draw_map(px, py, 'E', game);
	}
	else
	{
		game->map[py][px] = '0';
		game->map[py + y][px + x] = 'P';
		game->player_x = game->player_x + x;
		game->player_y = game->player_y + y;
		draw_map(game->player_x, game->player_y, 'P', game);
		draw_map(px, py, '0', game);
	}
	game->count_collect--;
}

void	move_to_floor(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = game->player_x;
	py = game->player_y;
	if (py == game->exit_y && px == game->exit_x)
	{
		game->map[py][px] = 'E';
		game->map[py + y][px + x] = 'P';
		game->player_x = game->player_x + x;
		game->player_y = game->player_y + y;
		draw_map(game->player_x, game->player_y, 'P', game);
		draw_map(px, py, 'E', game);
	}
	else
	{
		game->map[py][px] = '0';
		game->map[py + y][px + x] = 'P';
		game->player_x = game->player_x + x;
		game->player_y = game->player_y + y;
		draw_map(game->player_x, game->player_y, 'P', game);
		draw_map(px, py, '0', game);
	}
}

void	print_moves(t_game *game)
{
	char	*temp;

	game->move++;
	temp = ft_itoa(game->move);
	if (game->count_move)
		mlx_delete_image(game->mlx, game->count_move);
	game->count_move = mlx_put_string(game->mlx, temp, 0, 0);
	free(temp);
}

void	move_player(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = game->player_x;
	py = game->player_y;
	if (game->map[py + y][px + x] == '1')
		return ;
	if (game->map[py + y][px + x] == '0')
		move_to_floor (game, x, y);
	if (game->map[py + y][px + x] == 'C')
		take_collectible(game, x, y);
	if (game->map[py + y][px + x] == 'E' && game->count_collect != 0)
		exit_no_win (game, x, y);
	if (game->map[py + y][px + x] == 'E' && game->count_collect == 0)
	{
		ft_printf("YOU WIN IN %d MOVES\n", game->move);
		mlx_close_window(game->mlx);
		return ;
	}
	print_moves(game);
	ft_printf("%d\n", game->move);
}
