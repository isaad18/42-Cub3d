/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:43 by isaad             #+#    #+#             */
/*   Updated: 2022/11/10 22:50:44 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

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

	olddirx = all->size->dirx;
	oldplanex = all->size->planex;
	all->size->dirx = all->size->dirx * cos(all->size->rotspeed) - \
	all->size->diry * sin(all->size->rotspeed);
	all->size->diry = olddirx * sin(all->size->rotspeed)
		+ all->size->diry * cos(all->size->rotspeed);
	all->size->planex = all->size->planex * cos(all->size->rotspeed)
		- all->size->planey * sin(all->size->rotspeed);
	all->size->planey = oldplanex * sin(all->size->rotspeed)
		+ all->size->planey * cos(all->size->rotspeed);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key124(t_all *all)
{
	double	olddirx;
	double	oldplanex;

	olddirx = all->size->dirx;
	oldplanex = all->size->planex;
	all->size->dirx = all->size->dirx * cos(-all->size->rotspeed) - \
	all->size->diry * sin(-all->size->rotspeed);
	all->size->diry = olddirx * sin(-all->size->rotspeed)
		+ all->size->diry * cos(-all->size->rotspeed);
	all->size->planex = all->size->planex * cos(-all->size->rotspeed) - \
	all->size->planey * sin(-all->size->rotspeed);
	all->size->planey = oldplanex * sin(-all->size->rotspeed) + \
	all->size->planey * cos(-all->size->rotspeed);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}
