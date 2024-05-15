/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:26:50 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/15 16:30:07 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../get_libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

#define W_WIDTH 	128
#define W_HEIGHT 	128

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_img;

typedef struct t_texture
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_texture;

typedef struct s_game
{
	t_img		img;
	t_texture	t;

	int		count_player;
	int		count_collect;
	int		count_exit;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		line;
	int		col;
	int		move;
	char	**map;
	mlx_t	*mlx;
}	t_game;

int		ft_exit(char *message);
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
int		init_mlx(t_game *game);
void	check_matrix(t_game *game);
int		load_texture_n_image(t_game *game);
void	press_key(mlx_key_data_t keycode, void *param);
void	draw_map(int i, int j, char c, t_game *game);
void	move_player(t_game *game, int x, int y);

#endif