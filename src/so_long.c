/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:36:37 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/13 00:03:12 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		printf("the number of parameters must be 1!\n");
		return (0);
	}
	if (check_map_extension(argv[1]) == 0)
		return (0);
	if (map_gen(&game, argv[1]) == 0)
	{
		printf("the map doesn't exist!\n");
		return (0);
	}
	map_init(&game);
	if (check_map(&game) == 0)
		return (0);
	game_init(&game);
	load_sprites(&game);
	player_position(&game);
	printf("steps: %d\n", game.player.steps);
	mlx_loop_hook(game.vars.mlx, draw_game, &game);
	mlx_hook(game.vars.win, 02, 1L << 0, key_hook, &game);
	mlx_hook(game.vars.win, 17, 1L << 17, close_game, &game);
	mlx_loop(game.vars.mlx);
}
