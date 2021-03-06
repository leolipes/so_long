/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 01:13:40 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/12 23:17:56 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map
{
	char	**layout;
	t_img	wall;
	t_img	floor;
	t_img	collect;
	t_img	exit;
	t_img	open_exit;
	int		width;
	int		height;
}				t_map;

typedef struct s_player
{
	t_img	sprite[4];
	int		direction;
	int		steps;
	int		x;
	int		y;
}				t_player;

typedef struct s_game
{
	t_vars		vars;
	t_map		map;
	t_player	player;
	int			is_open;
}				t_game;

# define SPRITE_SIZE 32

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECT 'C'
# define EXIT 'E'

# define PLAYER_UP 0
# define PLAYER_LEFT 1
# define PLAYER_RIGHT 2
# define PLAYER_DOWN 3

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define ESC 65307

int		map_gen(t_game *game, char *map_set);
int		check_map_extension(char *file_name);
void	game_init(t_game *game);
void	map_init(t_game *game);
int		check_map(t_game *game);
void	load_sprites(t_game *game);
int		key_hook(int keycode, t_game *game);
int		player_position(t_game *game);
void	check_collectible(t_game *game);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
int		draw_game(t_game *game);
void	check_exit(t_game *game);
int		close_game(t_game *game);
void	free_map(t_game *game);

#endif
