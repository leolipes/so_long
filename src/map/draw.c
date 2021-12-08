/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:43:02 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/06 21:33:09 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(y < game->map.height)
	{
		while(x < game->map.width)
		{
			printf("%c", game->map.layout[y][x]);
			fflush(stdout);
			if (game->map.layout[y][x] == '1')
			{
				draw_image(game, x, y, &game->resources.wall);
			}
			if (game->map.layout[y][x] == '0' || game->map.layout[y][x] == 'P')
			{
				draw_image(game, x, y, &game->resources.floor);
			}
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

void	draw_image(t_game *game, int x, int y, t_data *img)
{
	//variáveis responsáveis pelos pixels do block
	int	pixel_img_x;
	int	pixel_img_y;
	int	pixel_color;
	x = x * BLOCK_SIZE;//tamanho do imagem completa
	y = y * BLOCK_SIZE;//tamanho do imagem completa
	pixel_img_x = 0;//pixel do imagem
	pixel_img_y = 0;//pixel do imagem
	//while responsável por percorrer todo o imagem
	while(pixel_img_y < BLOCK_SIZE)
	{
		while(pixel_img_x < BLOCK_SIZE)
		{
			pixel_color = get_pixel(img, pixel_img_x, pixel_img_y);
			put_pixel(&game->map.data, x + pixel_img_x, y + pixel_img_y, pixel_color);//somar x + pixel_img_x e y + pixel_img_y para pular de imagem;
			pixel_img_x++;
		}
		pixel_img_x = 0;
		pixel_img_y++;
	}
}

