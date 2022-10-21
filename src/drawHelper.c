#include "../Includes/Cub3d.h"

void	initDir(t_all *all)
{
	if(all->size->rayDirX < 0)
	{
		all->size->stepX = -1;
		all->size->sideDistX = (all->size->posX - \
		all->size->mapX) * all->size->deltaDistX;
	}
	else
	{
		all->size->stepX = 1;
		all->size->sideDistX = (all->size->mapX + 1.0 - \
		all->size->posX) * all->size->deltaDistX;
	}
	if(all->size->rayDirY < 0)
	{
		all->size->stepY = -1;
		all->size->sideDistY = (all->size->posY - \
		all->size->mapY) * all->size->deltaDistY;
	}
	else
	{
		all->size->stepY = 1;
		all->size->sideDistY = (all->size->mapY + 1.0 - \
		all->size->posY) * all->size->deltaDistY;
	}
}

void	getWallHit(t_all *all, char **map)
{
	while(all->size->hit == 0)
	{
		if(all->size->sideDistX < all->size->sideDistY)
		{
		  all->size->sideDistX += all->size->deltaDistX;
		  all->size->mapX += all->size->stepX;
		  all->size->side = 0;
		}
		else
		{
		  all->size->sideDistY += all->size->deltaDistY;
		  all->size->mapY += all->size->stepY;
		  all->size->side = 1;
		}
		if (map[all->size->mapX][all->size->mapY] != '0' && map[all->size->mapX][all->size->mapY] != 'P')
			all->size->hit = 1;
	}
}

void	getDrawPos(t_all *all, char **map, int *ii)
{
	if(all->size->side == 0)
		all->size->perpWallDist = (all->size->sideDistX - all->size->deltaDistX);
	else
		all->size->perpWallDist = (all->size->sideDistY - all->size->deltaDistY);
	all->mlx->lineHeight = (int)(all->size->win_y / all->size->perpWallDist);
	all->mlx->drawStart = -all->mlx->lineHeight / 2 + ((all->size->win_y / 2) + all->size->updown);
	if(all->mlx->drawStart < 0)
		all->mlx->drawStart = 0;
	all->mlx->drawEnd = all->mlx->lineHeight / 2 + ((all->size->win_y / 2) + all->size->updown);
	if(all->mlx->drawEnd >= all->size->win_y)
		all->mlx->drawEnd = all->size->win_y - 1;
	if(all->size->side == 0 && map[(int)all->size->mapX][(int)all->size->mapY] == '1')
	{
		all->size->wallX = all->size->posY + all->size->perpWallDist * all->size->rayDirY;
		*ii = 1;
	}
	else
	{
		all->size->wallX = all->size->posX + all->size->perpWallDist * all->size->rayDirX;
		*ii = 2;
	}
}