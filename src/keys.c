/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:33 by isaad             #+#    #+#             */
/*   Updated: 2022/10/22 22:17:27 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Cub3d.h"

int	closew(t_all *all)
{
	int	i;

	i = 0;
	if (all->mlx->mlx_win)
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
	if (all->mlx->tex)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex);
	if (all->mlx->tex2)
		mlx_destroy_image(all->mlx->mlx, all->mlx->tex2);
	if (all->mlx->img)
		mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	if (all->mlx->buffer)
	{
		while (i < all->size->win_y)
		{
			free(all->mlx->buffer[i]);
			i++;
		}
	}
	free(all->mlx->buffer);
	exit(0);
}

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
