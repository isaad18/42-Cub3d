/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:12 by isaad             #+#    #+#             */
/*   Updated: 2022/11/10 22:53:43 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all)
{
	mlx->ccolor = 0;
	mlx->fcolor = 0;
	all->mlx = mlx;
	all->mlx = mlx;
	all->exit = 0;
	all->textures = NULL;
	all->colors = NULL;
	all->splmap = NULL;
	all->map = NULL;
	all->mapl = NULL;
	all->map_file = NULL;
	size->where = 0;
	size->posx = 5;
	size->posy = 14;
	if (size->where == 0)
	{
		size->dirx = -1;
		size->diry = 0;
		size->planex = 0;
		size->planey = 0.66;
	}
	else if (size->where == 1)
	{
		size->dirx = 0;
		size->diry = 1;
		size->planex = 0.66;
		size->planey = 0;
	}
	else if (size->where == 2)
	{
		size->dirx = 1;
		size->diry = 0;
		size->planex = 0;
		size->planey = -0.66;
	}
	else if (size->where == 3)
	{
		size->dirx = 0;
		size->diry = -1;
		size->planex = -0.66;
		size->planey = 0;
	}
	size->win_x = 960;
	size->win_y = 540;
	size->camerax = 0;
	size->raydirx = 0;
	size->raydiry = 0;
	size->mapx = 0;
	size->mapy = 0;
	size->sidedistx = 0;
	size->sidedisty = 0;
	size->deltadistx = 0;
	size->deltadisty = 0;
	size->perpwalldist = 0;
	size->stepx = 0;
	size->stepy = 0;
	size->hit = 0;
	size->side = 0;
	size->updown = 0;
	size->lineheight = 0;
	size->drawstart = 0;
	size->drawend = 0;
	all->size = size;
}

void	initdrawing(t_all *all, int x)
{
	all->size->camerax = 2 * x / (double)all->size->win_x - 1;
	all->size->raydirx = all->size->dirx + all
		->size->planex * all->size->camerax;
	all->size->raydiry = all->size->diry + all->size
		->planey * all->size->camerax;
	all->size->mapx = (int)all->size->posx;
	all->size->mapy = (int)all->size->posy;
	if (all->size->raydirx == 0)
		all->size->deltadistx = 1e30;
	else
		all->size->deltadistx = fabs(1 / all->size->raydirx);
	if (all->size->raydiry == 0)
		all->size->deltadisty = 1e30;
	else
		all->size->deltadisty = fabs(1 / all->size->raydiry);
	all->size->hit = 0;
}
