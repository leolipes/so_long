/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:04:59 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/08 18:49:58 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.layout[y])
	{
		y++;
	}
	game->map.width = ft_strlen(game->map.layout[0]);
	game->map.height = y;
}
