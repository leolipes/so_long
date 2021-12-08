/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:43:58 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/08 00:02:53 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(void)
{
	t_game	game;
	
	set_map(&game, "./map_files/test.ber");
	game.vars.mlx = mlx_init();
	game.vars.win = mlx_new_window(game.vars.mlx, game.map.width * BLOCK_SIZE, game.map.height * BLOCK_SIZE, "so_long");
	load_sprites(&game);
	draw_map(&game);
	mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.map.data.img, 0, 0);
	mlx_loop (game.vars.mlx);
	return (0);	
}
