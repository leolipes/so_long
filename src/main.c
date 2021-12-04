/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:33:24 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/11/29 20:29:36 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;
	int 	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dest = data->addr + offset;
	*((unsigned int *)dest) = color;
}

int main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_data	img;

	x = 100;
	y = 50;
	mlx = mlx_init();
	if (!mlx)
		return (0);
	win = mlx_new_window(mlx, 500, 250, "so_long");
	if (!win)
		return (0);
	img.img = mlx_new_image(mlx, 500, 250);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while(y < 200)
	{
		my_mlx_pixel_put(&img, x, y, 0x776274);
		y++;
	}
	while(x < 250)
	{
		my_mlx_pixel_put(&img, x, 50, 0x776274);
		x++;
	}
	y = 50;
	while(y < 200)
	{
		my_mlx_pixel_put(&img, 250, y, 0x776274);
		y++;
	}
	while(x >= 100)
	{
		my_mlx_pixel_put(&img, x, 200, 0x776274);
		x--;
	}
	mlx_put_image_to_window (mlx, win, img.img, 0, 0);
	mlx_loop (mlx);
}
