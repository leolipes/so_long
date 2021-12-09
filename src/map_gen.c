/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:56:07 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/08 18:38:48 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* com o GNL vou ler todo o arquivo do mapa, uso o strdub pra ter oq dar free
** depois, uso o strjoin para juntar as linhas q estou lendo, depois uso split
** pra transformar tudo que li em matriz.
*/

int	map_gen(t_game *game, char *map_set)
{
	int		fd;
	char	*line;
	char	*last_line;
	char	*map;

	fd = open(map_set, O_RDONLY);
	if (fd == -1)
		return (0);
	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		last_line = map;
		map = ft_strjoin(last_line, line);
		free(last_line);
		free(line);
	}
	game->map.layout = ft_split(map, '\n');
	free(map);
	close(fd);
	return (0);
}
