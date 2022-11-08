/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:43 by isaad             #+#    #+#             */
/*   Updated: 2022/11/07 20:34:16 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	double	olddirx;
	double	oldplanex;

	olddirx = all->size->dirX;
	oldplanex = all->size->planeX;
	all->size->dirX = all->size->dirX * cos(all->size->rotSpeed) - \
	all->size->dirY * sin(all->size->rotSpeed);
	all->size->dirY = olddirx * sin(all->size->rotSpeed)
		+ all->size->dirY * cos(all->size->rotSpeed);
	all->size->planeX = all->size->planeX * cos(all->size->rotSpeed)
		- all->size->planeY * sin(all->size->rotSpeed);
	all->size->planeY = oldplanex * sin(all->size->rotSpeed)
		+ all->size->planeY * cos(all->size->rotSpeed);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key124(t_all *all)
{
	double	olddirx;
	double	oldplanex;

	olddirx = all->size->dirX;
	oldplanex = all->size->planeX;
	all->size->dirX = all->size->dirX * cos(-all->size->rotSpeed) - \
	all->size->dirY * sin(-all->size->rotSpeed);
	all->size->dirY = olddirx * sin(-all->size->rotSpeed)
		+ all->size->dirY * cos(-all->size->rotSpeed);
	all->size->planeX = all->size->planeX * cos(-all->size->rotSpeed) - \
	all->size->planeY * sin(-all->size->rotSpeed);
	all->size->planeY = oldplanex * sin(-all->size->rotSpeed) + \
	all->size->planeY * cos(-all->size->rotSpeed);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}
