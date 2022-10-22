/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:43 by isaad             #+#    #+#             */
/*   Updated: 2022/10/22 22:26:13 by isaad            ###   ########.fr       */
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
