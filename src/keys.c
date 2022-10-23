/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:33 by isaad             #+#    #+#             */
/*   Updated: 2022/10/23 14:35:47 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Cub3d.h"


void	key13(t_all *all)
{
	if (all->map[(int)
			(all->size->posX + all->size->dirX * all->size->moveSpeed)]
		[(int)(all->size->posY)] != '1')
		all->size->posX += all->size->dirX * all->size->moveSpeed;
	if (all->map[(int)
			(all->size->posX)][(int)
		(all->size->posY + all->size->dirY * all->size->moveSpeed)] != '1')
		all->size->posY += all->size->dirY * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key0(t_all *all)
{
	if (all->map[(int)
			(all->size->posX - all->size->dirY * all->size->moveSpeed)]
		[(int)(all->size->posY)] != '1')
		all->size->posX -= all->size->dirY * all->size->moveSpeed;
	if (all->map[(int)(all->size->posX)]
		[(int)(all->size->posY
			+ all->size->dirX * all->size->moveSpeed)] != '1')
			all->size->posY += all->size->dirX * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key1(t_all *all)
{
	if (all->map[(int)(all->size->posX - all->size->dirX
			* all->size->moveSpeed)][(int)(all->size->posY)] != '1')
				all->size->posX -= all->size->dirX * all->size->moveSpeed;
	if (all->map[(int)(all->size->posX)]
		[(int)(all->size->posY - all->size->dirY
			* all->size->moveSpeed)] != '1')
			all->size->posY -= all->size->dirY * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key2(t_all *all)
{
	if (all->map[(int)(all->size->posX + all->size->dirY
			* all->size->moveSpeed)][(int)(all->size->posY)] != '1')
				all->size->posX += all->size->dirY * all->size->moveSpeed;
	if (all->map[(int)(all->size->posX)]
		[(int)(all->size->posY - all->size->dirX
			* all->size->moveSpeed)] != '1')
			all->size->posY -= all->size->dirX * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}
