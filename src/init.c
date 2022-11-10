/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:12 by isaad             #+#    #+#             */
/*   Updated: 2022/11/11 03:01:32 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all)
{
	ft_bzero(size, sizeof(t_size));
	ft_bzero(mlx, sizeof(t_mlx));
	ft_bzero(all, sizeof(t_all));
	all->mlx = mlx;
	size->posx = 3;
	size->posy = 27;
	direction(size);
	size->win_x = 960;
	size->win_y = 540;
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
