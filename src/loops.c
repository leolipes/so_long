/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:02:47 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/11/30 17:08:37 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	t_data	deer;
	t_data	map;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}				t_vars;


int	render_next_frame(t_vars *loop)
{
	mlx_put_image_to_window(loop->mlx, loop->win, loop->map.img, 0, 0);
	mlx_put_image_to_window(loop->mlx, loop->win, loop->deer.img, loop->x, loop->y);
	return (0);
}

int	key_hook(int keycode, t_vars *loop)
{
	if (keycode == 100)
	{
		loop->x+=32;
	}
	if (keycode == 115)
	{
		loop->y+=32;
	}
	if (keycode == 97)
	{
		loop->x-=32;
	}
	if (keycode == 119)
	{
		loop->y-=32;
	}
	printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	loop;
	char	*relative_path = "./src/deer.xpm";
	int		img_width;
	int		img_height;
	
	loop.x = 0;
	loop.y = 0;
	loop.mlx = mlx_init();
	loop.win = mlx_new_window(loop.mlx, 432, 432, "loop");
	loop.deer.img = mlx_xpm_file_to_image(loop.mlx, relative_path, &img_width, &img_height);
	loop.map.img = mlx_xpm_file_to_image(loop.mlx, "./src/map.xpm", &img_width, &img_height);
	mlx_loop_hook(loop.mlx, render_next_frame, &loop);
	//mlx_key_hook(loop.win, key_hook, &loop);
	mlx_hook(loop.win, 2, 1L<<0, key_hook, &loop);
	mlx_loop(loop.mlx);
}
