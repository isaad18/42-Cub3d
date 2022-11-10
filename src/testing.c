/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:29:44 by isaad             #+#    #+#             */
/*   Updated: 2022/11/10 20:45:40 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	mlx_main_loop(t_all *all, char **map)
{
	all->mlx->mlx = mlx_init();
	all->mlx->mlx_win = mlx_new_window(all->mlx->mlx, all->\
	size->win_x, all->size->win_y, "cub3d");
	initimgs(all);
	print_plz(all, map);
	mlx_hook(all->mlx->mlx_win, 2, (1L << 0), key, all);
	mlx_hook(all->mlx->mlx_win, 6, 1L << 6, mouse, all);
	mlx_hook(all->mlx->mlx_win, 17, 1L << 5, ft_quit, all);
	mlx_loop(all->mlx->mlx);
}

void	getandfillwalls(t_all *all, int y, int x, int ii)
{
	all->size->wallX = (double)all->size->wallX - (int)all->size->wallX;
	all->mlx->texX = (int)(all->size->wallX * (double)64);
	if (all->size->side == 0 && all->size->rayDirX > 0)
		all->mlx->texX = 64 - all->mlx->texX - 1;
	if (all->size->side == 1 && all->size->rayDirY < 0)
		all->mlx->texX = 64 - all->mlx->texX - 1;
	all->size->step = 1.0 * 64 / all->mlx->lineHeight;
	all->size->texPos = (all->mlx->drawStart - ((all->size->win_y / 2)
				+ all->size->updown) + all->mlx->lineHeight / 2)
		* all->size->step;
	y = all->mlx->drawStart;
	while (y < all->mlx->drawEnd)
	{
		all->mlx->texY = (int)all->size->texPos & (64 - 1);
		all->size->texPos += all->size->step;
		gettexture(all, ii);
		all->mlx->buffer[y][x] = all->size->color;
		y++;
	}
}

void	initimgs(t_all *all)
{
	int	xx;

	xx = 0;
	all->mlx->tex = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[0], &all->mlx->w, &all->mlx->h);
	all->mlx->text = (int *)mlx_get_data_addr(all->mlx
			->tex, &all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex2 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[1], &all->mlx->w, &all->mlx->h);
	all->mlx->text2 = (int *)mlx_get_data_addr(all->mlx
			->tex2, &all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex3 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[2], &all->mlx->w, &all->mlx->h);
	all->mlx->text3 = (int *)mlx_get_data_addr(all->mlx->tex3,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->tex4 = mlx_xpm_file_to_image(all->mlx
			->mlx, all->textures[3], &all->mlx->w, &all->mlx->h);
	all->mlx->text4 = (int *)mlx_get_data_addr(all->mlx->tex4,
			&all->mlx->b, &all->mlx->h, &all->mlx->w);
	all->mlx->buffer = malloc(sizeof(int *) * all->size->win_y);
	while (xx < all->size->win_y)
	{
		all->mlx->buffer[xx] = malloc(sizeof(int) * all->size->win_x);
		xx++;
	}
}

void	clearbuffer(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->size->win_y)
	{
		j = 0;
		while (j < all->size->win_x)
		{
			all->mlx->buffer[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	print_plz(t_all *all, char **map)
{
	int	ii;
	int	x;
	int	y;

	ii = 0;
	x = 0;
	y = 0;
	clearbuffer(all);
	while (x < all->size->win_x)
	{
		initdrawing(all, x);
		initdir(all);
		getwallhit(all, map);
		getdrawpos(all, map, &ii);
		getandfillwalls(all, y, x, ii);
		y = 0;
		fill_the_void(all, y, x);
		x++;
	}
	drawall(all, all->mlx->buffer);
	all->size->moveSpeed = 0.12;
	all->size->rotSpeed = 0.055;
	return (0);
}
