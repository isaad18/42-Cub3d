#include "../Includes/Cub3d.h"

void	keyup(t_all *all)
{
	all->size->updown += 7;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	keydown(t_all *all)
{
	all->size->updown -= 7;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key123(t_all *all)
{
	double oldDirX = all->size->dirX;
	double oldPlaneX = all->size->planeX;

	all->size->dirX = all->size->dirX * cos(all->size->rotSpeed) - \
	all->size->dirY * sin(all->size->rotSpeed);
	all->size->dirY = oldDirX * sin(all->size->rotSpeed) + all->size->dirY\
	 * cos(all->size->rotSpeed);
	all->size->planeX = all->size->planeX * cos(all->size->rotSpeed)\
	 - all->size->planeY * sin(all->size->rotSpeed);
	all->size->planeY = oldPlaneX * sin(all->size->rotSpeed)\
	 + all->size->planeY * cos(all->size->rotSpeed);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key124(t_all *all)
{
	double oldDirX = all->size->dirX;
	double oldPlaneX = all->size->planeX;

	all->size->dirX = all->size->dirX * cos(-all->size->rotSpeed) - \
	all->size->dirY * sin(-all->size->rotSpeed);
	all->size->dirY = oldDirX * sin(-all->size->rotSpeed) + all->size->dirY\
	 * cos(-all->size->rotSpeed);
	all->size->planeX = all->size->planeX * cos(-all->size->rotSpeed) - \
	all->size->planeY * sin(-all->size->rotSpeed);
	all->size->planeY = oldPlaneX * sin(-all->size->rotSpeed) + \
	all->size->planeY * cos(-all->size->rotSpeed);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}