/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 23:21:07 by leolipes          #+#    #+#             */
/*   Updated: 2021/12/04 18:58:14 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 30
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*join(int fd, char *buf_read, char *temp);
char	*alloc_and_free(char *temp, char *buf_read, int aux);
char	*alloc_buf(void);
char	*ftsubstr(char const *s, unsigned int start, size_t len);
char	*ftstrjoin(char *s1, char *s2);
char	*ftstrchr(const char *s, int c);
void	*ftcalloc(size_t nmemb, size_t size);
size_t	ftstrlen(const char *str);

#endif
