/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:59:17 by lfilipe-          #+#    #+#             */
/*   Updated: 2021/11/30 13:59:20 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	update(int keycode, t_vars *vars)
{
	//static int	x;

	if (keycode == 32)
	{
		mlx_clear_window(vars->mlx, vars->win);
		printf("vc apagou sua arte!%d\n", keycode);
		//x++;
	}
}

int	mouse_click (int button, int x, int y, t_vars *vars)
{
	printf ("botao clicado: %d\nx = %d\ny = %d\n", button, x, y);
	mlx_pixel_put(vars->mlx, vars->win, x, y, 0x0000ff);
	
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();//armazenei na vareavel mlx o servidor...
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");//salvei a tela na win...
	mlx_key_hook(vars.win, update, &vars);
	mlx_mouse_hook(vars.win, mouse_click, &vars);
	//mlx_hook(vars.win, 4, 1L<<2, mouse_click, &vars);
	mlx_loop(vars.mlx);
}