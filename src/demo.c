/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:51:08 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/01 23:42:58 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			   t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}			   t_vars;

typedef struct s_game {
	t_vars	vars;
	t_data	character;
	t_data	map;
} 			   t_game;

int	file_images(t_game *game)
{
	int	z;
	
	game->character.img = mlx_xpm_file_to_image(game->vars.mlx, "./src/deer.xpm", &z, &z);
	game->map.img = mlx_xpm_file_to_image(game->vars.mlx, "./src/map.xpm", &z, &z);
	return (0);
}

int	render_next_frame(t_game *game)
{
	
	mlx_put_image_to_window (game->vars.mlx, game->vars.win, game->map.img, 0, 0);
	mlx_put_image_to_window (game->vars.mlx, game->vars.win, game->character.img, game->vars.x, game->vars.y);
	return (0);
}

int	movimentation(int keycode, t_game *game)
{
	if (keycode == 100 || keycode == 65363)
	{
		game->vars.x+=32;
	}
	if (keycode == 115 || keycode == 65364)
	{
		game->vars.y+=32;
	}
	if (keycode == 97 || keycode == 65361)
	{
		game->vars.x-=32;
	}
	if (keycode == 119 || keycode == 65362)
	{
		game->vars.y-=32;
	}
	printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.vars.x = 0;
	game.vars.y = 0;
	game.vars.mlx = mlx_init();
	game.vars.win = mlx_new_window (game.vars.mlx, 432, 432, "demo");
	file_images(&game);
	mlx_loop_hook(game.vars.mlx, render_next_frame, &game.vars);
	mlx_hook(game.vars.win, 2, 1L<<0, movimentation, &game.vars);
	mlx_loop(game.vars.mlx);
	return (0);
}
