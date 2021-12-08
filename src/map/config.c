/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:48:52 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/06 21:35:20 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	set_map(t_game *game, char *namemap)//configs do mapa
{
	int		fd;
	int		nb_line;
	size_t	i;
	char 	*line;

	nb_line = 0;
	i = 0;
	fd = open (namemap, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while(line != 0)
	{
		nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	game->map.layout = ft_calloc(nb_line, sizeof(char *));
	if (!game->map.layout)
		return (0);
	close (fd);
	fd = open (namemap, O_RDONLY);
	line = get_next_line(fd);
	while(line != 0)
	{
		game->map.layout[i] = line;
		if (game->map.layout[i][ft_strlen(line) - 1] == '\n')
			game->map.layout[i][ft_strlen(line) - 1] = '\0';
		i++;
		line = get_next_line(fd);
	}
	game->map.height = nb_line;
	game->map.width = ft_strlen(game->map.layout[0]);
	close(fd);
	return (0);
}
