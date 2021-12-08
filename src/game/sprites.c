/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:24:35 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/06 21:46:00 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int		get_pixel(t_data *data, int x, int y)//pega o pixel
{
	char	*dest;
	int		bytes;

	bytes = (data->bits_per_pixel / 8);
	dest = data->addr + (y * data->line_length + x * bytes);
	return (*(unsigned int*)dest);
}

void	put_pixel(t_data *data, int x, int y, int color)//coloca o pixel
{
	char	*dest;
	int		bytes;

	bytes = (data->bits_per_pixel / 8);
	dest = data->addr + (y * data->line_length + x * bytes);
	*(unsigned int*)dest = color;
}


void	load_sprites(t_game *game)//carregar as imgs
{
	game->resources.floor.img = mlx_xpm_file_to_image(game->vars.mlx, "./assets/sprites/floor.xpm", &game->resources.floor.width, &game->resources.floor.height);
	game->resources.wall.img = mlx_xpm_file_to_image(game->vars.mlx, "./assets/sprites/wall.xpm", &game->resources.wall.width, &game->resources.wall.height);
	game->map.data.img = mlx_new_image(game->vars.mlx, game->map.width * BLOCK_SIZE, game->map.height * BLOCK_SIZE);//cria uma nova imagem, armazena em game.map.data.img(imagem completa do mapa)
	game->map.data.addr = mlx_get_data_addr(game->map.data.img, &game->map.data.bits_per_pixel, &game->map.data.line_length, &game->map.data.endian);//endereço aonde a imagem começa na memoria
	game->resources.floor.addr = mlx_get_data_addr(game->resources.floor.img, &game->resources.floor.bits_per_pixel, &game->resources.floor.line_length, &game->resources.floor.endian);//endereço aonde a imagem começa na memoria
	game->resources.wall.addr = mlx_get_data_addr(game->resources.wall.img, &game->resources.wall.bits_per_pixel, &game->resources.wall.line_length, &game->resources.wall.endian);//endereço aonde a imagem começa na memoria
}
