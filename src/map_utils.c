/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:07 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/10 18:57:11 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_char(char c)
{
	return ((c == '1') || (c == '0') || (c == 'P')
		|| (c == 'C') || (c == 'E'));
}

void	valid_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == (game->line - 1))
			{
				if (game->map[i][j] != '1' && game->map[i][j])
					frexit("Error\nInvalid walls line", game);
			}
			if (game->map[i][0] != '1' || game->map[i][game->col - 1] != '1')
				frexit("Error\nInvalid walls col", game);
			j++;
		}
		i++;
	}
}

void	count_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!valid_char(game->map[i][j]))
				frexit("Error\nInvalid character\n", game);
			if (game->map[i][j] == 'P')
				game->count_player++;
			if (game->map[i][j] == 'E')
				game->count_exit++;
			if (game->map[i][j] == 'C')
				game->count_collect++;
			j++;
		}
		i++;
	}
}

void	position_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

void	valid_elements(t_game *game)
{
	if (game->count_player != 1)
		frexit ("Invalid number of players", game);
	if (game->count_exit != 1)
		frexit ("Invalid number of exits", game);
	if (game->count_collect < 1)
		frexit ("Invalid number of collectibles", game);
}
