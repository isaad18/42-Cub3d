/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:33 by isaad             #+#    #+#             */
/*   Updated: 2022/11/10 22:56:46 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	key13(t_all *all)
{
	if (all->map[(int)
			(all->size->posx + all->size->dirx * all->size->movespeed)]
		[(int)(all->size->posy)] != '1')
		all->size->posx += all->size->dirx * all->size->movespeed;
	if (all->map[(int)
			(all->size->posx)][(int)
		(all->size->posy + all->size->diry * all->size->movespeed)] != '1')
		all->size->posy += all->size->diry * all->size->movespeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key0(t_all *all)
{
	if (all->map[(int)
			(all->size->posx - all->size->diry * all->size->movespeed)]
		[(int)(all->size->posy)] != '1')
		all->size->posx -= all->size->diry * all->size->movespeed;
	if (all->map[(int)(all->size->posx)]
		[(int)(all->size->posy
			+ all->size->dirx * all->size->movespeed)] != '1')
			all->size->posy += all->size->dirx * all->size->movespeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key1(t_all *all)
{
	if (all->map[(int)(all->size->posx - all->size->dirx
			* all->size->movespeed)][(int)(all->size->posy)] != '1')
				all->size->posx -= all->size->dirx * all->size->movespeed;
	if (all->map[(int)(all->size->posx)]
		[(int)(all->size->posy - all->size->diry
			* all->size->movespeed)] != '1')
			all->size->posy -= all->size->diry * all->size->movespeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key2(t_all *all)
{
	if (all->map[(int)(all->size->posx + all->size->diry
			* all->size->movespeed)][(int)(all->size->posy)] != '1')
				all->size->posx += all->size->diry * all->size->movespeed;
	if (all->map[(int)(all->size->posx)]
		[(int)(all->size->posy - all->size->dirx
			* all->size->movespeed)] != '1')
			all->size->posy -= all->size->dirx * all->size->movespeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}
