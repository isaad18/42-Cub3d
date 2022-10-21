#include "../Includes/Cub3d.h"

int	closew(t_all *all)
{
	mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
	exit(0);
}

void	key13(t_all *all)
{
	if(all->map[(int)(all->size->posX + all->size->dirX * all->size->moveSpeed)][(int)\
	(all->size->posY)] != '1') all->size->posX += all->size->dirX * all->size->moveSpeed;
	if(all->map[(int)(all->size->posX)][(int)(all->size->posY + all->size->dirY * \
	all->size->moveSpeed)] != '1') all->size->posY += all->size->dirY * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key0(t_all *all)
{
	if(all->map[(int)(all->size->posX - all->size->dirY * all->size->moveSpeed)][(int)\
	(all->size->posY)] != '1') all->size->posX -= all->size->dirY * all->size->moveSpeed;
	if(all->map[(int)(all->size->posX)][(int)(all->size->posY + all->size->dirX * \
	all->size->moveSpeed)] != '1') all->size->posY += all->size->dirX * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key1(t_all *all)
{
	if(all->map[(int)(all->size->posX - all->size->dirX * all->size->moveSpeed)][(int)\
	(all->size->posY)] != '1') all->size->posX -= all->size->dirX * all->size->moveSpeed;
	if(all->map[(int)(all->size->posX)][(int)(all->size->posY - all->size->dirY * \
	all->size->moveSpeed)] != '1') all->size->posY -= all->size->dirY * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key2(t_all *all)
{
	if(all->map[(int)(all->size->posX + all->size->dirY * all->size->moveSpeed)][(int)\
	(all->size->posY)] != '1') all->size->posX += all->size->dirY * all->size->moveSpeed;
	if(all->map[(int)(all->size->posX)][(int)(all->size->posY - all->size->dirX * \
	all->size->moveSpeed)] != '1') all->size->posY -= all->size->dirX * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}