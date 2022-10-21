#include "../Includes/Cub3d.h"

void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all)
{
	mlx->Ccolor = 0x87CEEB;
	mlx->Fcolor = 0x964B00;
	all->mlx = mlx;
	size->where = 3;
	size->posX = 5;
	size->posY = 14;
	if (size->where == 0)
	{
		size->dirX = -1;
		size->dirY = 0;
		size->planeX = 0;
		size->planeY = 0.66;
	}
	else if (size->where == 1)
	{
		size->dirX = 0;
		size->dirY = 1;
		size->planeX = 0.66;
		size->planeY = 0;
	}
	else if (size->where == 2)
	{
		size->dirX = 1;
		size->dirY = 0;
		size->planeX = 0;
		size->planeY = -0.66;
	}
	else if (size->where == 3)
	{
		size->dirX = 0;
		size->dirY = -1;
		size->planeX = -0.66;
		size->planeY = 0;
	}
	size->win_x = 740;
	size->win_y = 580;
	size->cameraX = 0;
	size->rayDirX = 0;
	size->rayDirY = 0;
	size->mapX = 0;
	size->mapY = 0;
	size->sideDistX = 0;
	size->sideDistY = 0;
	size->deltaDistX = 0;
	size->deltaDistY = 0;
	size->perpWallDist = 0;
	size->stepX = 0;
	size->stepY = 0;
	size->hit = 0;
	size->side = 0;
	size->updown = 0;
	size->lineHeight = 0;
	size->drawStart = 0;
	size->drawEnd = 0;
	all->size = size;
}

void	initDrawing(t_all *all, int x)
{
	all->size->cameraX = 2 * x / (double)all->size->win_x - 1;
	all->size->rayDirX = all->size->dirX + all->size->planeX * all->size->cameraX;
	all->size->rayDirY = all->size->dirY + all->size->planeY * all->size->cameraX;
	all->size->mapX = (int)all->size->posX;
	all->size->mapY = (int)all->size->posY;
	all->size->deltaDistX = (all->size->rayDirX == 0) ? 1e30 : fabs(1 / all->size->rayDirX);
	all->size->deltaDistY = (all->size->rayDirY == 0) ? 1e30 : fabs(1 / all->size->rayDirY);
	all->size->hit = 0;
}
