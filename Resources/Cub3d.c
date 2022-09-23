#include "../Includes/Cub3d.h"

void	mlx_main_loop(t_all *all)
{
	all->mlx = mlx_init();
	all->mlx->mlx_win = mlx_new_window(all->mlx, all->size->win_x, all->size->win_y, "Cub3d");
	mlx_loop(all->mlx);
}

int main(int argc, char **argv)
{
	t_all	all;
	t_mlx	mlx;
	t_size	size;

	(void)argc;
	(void)argv;
	all.mlx = &mlx;
	all.size = &size;
	size.win_x = 1500;
	size.win_y = 850;
	all.size = &size;
	mlx_main_loop(&all);
}
