/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolipes <leolipes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:42:54 by leolipes          #+#    #+#             */
/*   Updated: 2021/08/04 11:40:21 by leolipes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	count;

	d = 0;
	s = 0;
	count = 0;
	while (dest[d] && d < size)
		d++;
	while (src[s] && (d + s + 1) < size)
	{
		dest[d + s] = src[s];
		s++;
	}
	if (d < size)
		dest[d + s] = '\0';
	while (src[count] != '\0')
		count++;
	return (d + count);
}
