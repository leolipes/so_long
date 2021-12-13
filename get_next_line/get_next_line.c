/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:04:13 by leolipes          #+#    #+#             */
/*   Updated: 2021/12/04 18:54:32 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_and_free(char *temp, char *buf_read, int aux)
{
	char	*line;

	line = ftsubstr(temp, 0, aux + 1);
	free(temp);
	free(buf_read);
	return (line);
}

char	*join(int fd, char *buf_read, char *temp)
{
	char	*aux_temp;
	int		verification;

	verification = 1;
	while (verification)
	{
		verification = read (fd, buf_read, BUFFER_SIZE);
		if (verification <= 0 && temp[0] == 0)
		{
			free(temp);
			free(buf_read);
			return (NULL);
		}
		buf_read[verification] = '\0';
		aux_temp = temp;
		temp = ftstrjoin(temp, buf_read);
		if (!temp)
			return (NULL);
		free(aux_temp);
		if (ftstrchr(temp, '\n'))
			break ;
	}
	return (temp);
}

char	*alloc_buf(void)
{
	char		*buf_read;

	buf_read = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf_read)
	{
		free(buf_read);
		return (NULL);
	}
	return (buf_read);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf_read;
	char		*temp;
	size_t		aux;

	buf_read = alloc_buf();
	if (!buf_read)
		return (NULL);
	if (backup)
		temp = backup;
	else
		temp = ftcalloc(1, sizeof(char));
	temp = join(fd, buf_read, temp);
	if (!temp || !buf_read)
		return (NULL);
	aux = 0;
	while (temp[aux] != '\n' && temp[aux] != '\0')
		aux++;
	backup = ftsubstr(temp, aux + 1, -1);
	if (*backup == '\0')
	{
		free(backup);
		backup = 0;
	}
	return (alloc_and_free(temp, buf_read, aux));
}
