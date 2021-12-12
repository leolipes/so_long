/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:14:49 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/12 01:32:28 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game);
	check_collectible(game);
	return (0);
}
