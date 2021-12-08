/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:46:48 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/06 21:32:25 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H /*se so_long.h nao tiver definido (proteção para evitar erro)*/
# define SO_LONG_H //vou defini-lo
# define BLOCK_SIZE 32

# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			   t_data;

typedef struct	s_resources
{
	t_data	wall;
	t_data	floor;
}				t_resources;

typedef struct	s_map
{
	t_data	data;
	char	**layout;
	int		width;
	int		height;
}				t_map;

typedef struct	s_game 
{
	t_resources	resources;
	t_vars		vars;
	t_map		map;
	
}				t_game;

/*
**	@brief This function stores map information and its layout
*/
int		set_map(t_game *game, char *namemap);

/*
** 	@brief This function load all the sprites of the game
*/
void	load_sprites(t_game *game);

/*
** 	@brief This function draw maybe
*/
void	draw_map(t_game *game);
/*
** 	@brief this function puts coordinate pixel
*/
void	put_pixel(t_data *data, int x, int y, int color);
/*
** 	@brief This function gets coordinate pixel
*/
int		get_pixel(t_data *data, int x, int y);
/*
** 	@brief This function draw the block pixel by pixel
*/
void	draw_image(t_game *game, int x, int y, t_data *img);

#endif
