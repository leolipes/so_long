#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	t_vars	screen;
	t_data	data;
	char	*relative_path = "./src/deer.xpm";
	int		img_width;
	int		img_height;

	screen.mlx = mlx_init();
	screen.win = mlx_new_window (screen.mlx, 640, 480, "deer");
	data.img = mlx_xpm_file_to_image(screen.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(screen.mlx, screen.win, data.img, 0, 0);
	mlx_loop(screen.mlx);
}