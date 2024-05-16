/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:12:45 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/16 16:20:44 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(t_game *game)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = (char **)malloc(sizeof(char *) * game->line + 1);
	if (!copy_map)
		return (NULL);
	while (i < game->line)
	{
		copy_map[i] = ft_strdup(game->map[i]);
		if (!copy_map[i])
		{
			free_matrix(copy_map);
			return (NULL);
		}
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

static bool	floodfill(char **map, t_game game, int x, int y)
{
	static bool	exit = false;
	static int	collect = 0;

	if (map[y][x] == '1' || map[y][x] == '*')
	{
		return (false);
	}
	if (game.map[y][x] == 'E')
		exit = true;
	if (game.map[y][x] == 'C')
		collect++;
	map[y][x] = '*';
	floodfill(map, game, x + 1, y);
	floodfill(map, game, x - 1, y);
	floodfill(map, game, x, y + 1);
	floodfill(map, game, x, y - 1);
	if (exit == true && game.count_collect == collect)
		return (true);
	else
		return (false);
}

int	valid_path(t_game *game)
{
	char	**copy_map;

	copy_map = ft_copy_map(game);
	if (floodfill(copy_map, *game, game->player_x, game->player_y) == false)
	{
		free_matrix (copy_map);
		return (0);
	}
	free_matrix (copy_map);
	return (1);
}
