#include "../Includes/Cub3d.h"

void	mlx_main_loop(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->size->win_x, mlx->size->win_y, "Cub3d");
	mlx_loop(mlx->mlx);
}

int main(int argc, char **argv)
{
	t_mlx	mlx;
	t_size	size;

	(void)argc;
	(void)argv;
	size.win_x = 1500;
	size.win_y = 850;
	mlx.size = &size;
	mlx_main_loop(&mlx);
}