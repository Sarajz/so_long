/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:53:37 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/13 16:42:30 by sarajime         ###   ########.fr       */
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
		game->map[i] = ft_strtrim(game->map[i], "\n");
	}
	game->map[i] = NULL;
	game->col = ft_strlen(game->map[i - 1]);
}

int	main(int argc, char **argv)
{
	t_game	game;

	int	fd = open(argv[1], O_RDONLY);
	check_args(argc, argv);
	start_game(&game);
	get_map(&game, fd, argv);
	valid_map(&game, fd);
	// while(*game.map)
	// 	printf("%s\n", *game.map++);
	// printf("%d\n", game.line);
		// printf("%d\n", game.count_player);
		// printf("%d\n", game.count_exit);
		// printf("%d\n", game.count_collect);
}
