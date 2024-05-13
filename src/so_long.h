/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:26:50 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/13 17:15:28 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../get_libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_game
{
	int		count_player;
	int		count_collect;
	int		count_exit;

	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;

	int		line;
	int		col;

	char	**map;

	mlx_t	*mlx;
}	t_game;

void	ft_exit(char *message);
void	frexit(char *s, t_game *game);
void	free_map(t_game *game);
void	free_matrix(char **map);
void	start_game(t_game *game);
void	get_map(t_game *game, int fd, char **argv);
size_t	n_strlen(const char *s);
int		size_ok(int fd);
int		size_x(char *line);
int		size_y(char **line);


void	check_args(int argc, char **argv);
void	valid_map(t_game *game, int fd);
int		valid_char(char c);
void	valid_walls(t_game *game);
void	count_elements(t_game *game);
void	position_elements(t_game *game);
void	valid_elements(t_game *game);

char	**ft_copy_map(t_game *game);
int		valid_path(t_game *game);


#endif