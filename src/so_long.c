/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:36:37 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/09 20:07:24 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;

	map_gen(&game, "./assets/maps/map.ber");//lendo mapa
	map_init(&game);//width e height do mapa
	if (check_map(&game) == 0)
		return (0);
	game_init(&game);//iniciando a biblioteca e janela do game
	load_sprites(&game);//carregando as sprites
	player_position(&game);//saber onde o personagem está
	mlx_loop_hook(game.vars.mlx, draw_game, &game);//chamar essa função várias vezes
	mlx_key_hook(game.vars.win, key_hook, &game);//evento de teclas
	mlx_hook(game.vars.win, 17, 1L << 17, close_game, &game);
	mlx_loop(game.vars.mlx);
}
