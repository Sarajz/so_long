/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:53:37 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/15 18:43:24 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	game->count_exit = 0;
	game->count_collect = 0;
	game->count_player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->line = 0;
	game->col = 0;
}

void	get_map(t_game *game, int fd, char **argv)
{
	int		i;
	char	*c;
	int		fd2;

	i = -1;
	c = ft_strdup("");
	fd2 = open(argv[1], O_RDONLY);
	while (c)
	{
		free(c);
		c = get_next_line(fd);
		i++;
	}
	game->line = i;
	game->map = (char **)malloc(sizeof(char *) * i);
	if (!game->map)
		frexit("Error\n", game);
	i = -1;
	while (++i < game->line)
	{
		game->map[i] = get_next_line(fd2);
		char *temp = game->map[i];
		game->map[i] = ft_strtrim(game->map[i], "\n");
		free(temp);
	}
	game->map[i] = NULL;
	game->col = ft_strlen(game->map[i - 1]);
}

void leaks()
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	atexit(leaks);
	fd = open(argv[1], O_RDONLY);
	check_args(argc, argv);
	start_game(&game);
	get_map(&game, fd, argv);
	valid_map(&game, fd);
	if (init_mlx(&game))
		frexit("MLX Error", &game);
	free_map(&game);
}
