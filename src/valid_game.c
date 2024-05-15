/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:21:46 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/15 17:35:17 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		ft_exit("Error\nInvalid number of argument\n");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_exit("Error\nFile must be of type \".ber\"\n");
		exit(0);
	}
}

void	valid_map(t_game *game, int fd)
{
	if (!size_ok(fd))
		frexit("Invalid map dimensions", game);
	count_elements(game);
	position_elements(game);
	valid_elements(game);
	valid_walls(game);
	if (!valid_path(game))
		frexit("Invalid path", game);
}
