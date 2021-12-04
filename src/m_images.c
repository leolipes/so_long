/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_images.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:49:25 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/12/01 16:52:42 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}			   t_vars;

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	
}