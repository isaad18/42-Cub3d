/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:34:49 by isaad             #+#    #+#             */
/*   Updated: 2022/11/08 13:12:54 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	drawall(t_all *all, int **buffer)
{
	int	i;
	int	j;
	int	*texture;

	i = 0;
	j = 0;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	all->mlx->img = mlx_new_image(all->mlx->mlx,
			all->size->win_x, all->size->win_y);
	texture = (int *)mlx_get_data_addr(all->mlx->img, &all->mlx->b,
			&all->mlx->w, &all->mlx->h);
	while (j < all->size->win_y)
	{
		i = 0;
		while (i < all->size->win_x)
		{
			texture[j * all->size->win_x + i] = buffer[j][i];
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(all->mlx->mlx,
		all->mlx->mlx_win, all->mlx->img, 0, 0);
}

void	filldown(t_all *all, int y, int x)
{
	while (y < all->size->win_y)
	{
		if (all->mlx->drawEnd < 0 || all->mlx->drawEnd < all->mlx->drawStart)
			break ;
		all->mlx->buffer[y][x] = all->mlx->Fcolor;
		y++;
	}
}

void	fill_the_void(t_all *all, int y, int x)
{
	while (y < all->mlx->drawStart)
	{
		if (all->mlx->drawStart < 0 || all->mlx->drawStart > all->mlx->drawEnd)
			break ;
		all->mlx->buffer[y][x] = all->mlx->Ccolor;
		y++;
	}
	y = all->mlx->drawEnd;
	filldown(all, y, x);
	y = 0;
	while (y < all->size->win_y)
	{
		if (all->mlx->buffer[y][x] == 0 && all->size->updown > 0 && \
		(y < all->mlx->drawStart || y > all->mlx->drawEnd))
			all->mlx->buffer[y][x] = all->mlx->Ccolor;
		if (all->mlx->buffer[y][x] == 0 && all->size->updown < 0 && \
		(y < all->mlx->drawStart || y > all->mlx->drawEnd))
			all->mlx->buffer[y][x] = all->mlx->Fcolor;
		y++;
	}
}

void	gettexture(t_all *all, int ii)
{
	if (ii == 1)
		all->size->color = mlx_get_color_value(all->mlx->mlx, all->mlx->text
			[(64 * all->mlx->texY) + all->mlx->texX]);
	else if (ii == 2)
		all->size->color = mlx_get_color_value(all->mlx->mlx, all->mlx
				->text2[(64 * all->mlx->texY) + all->mlx->texX]);
	else if (ii == 3)
		all->size->color = mlx_get_color_value(all->mlx->mlx, all->mlx
				->text3[(64 * all->mlx->texY) + all->mlx->texX]);
	else if (ii == 4)
		all->size->color = mlx_get_color_value(all->mlx->mlx, all->mlx
				->text4[(64 * all->mlx->texY) + all->mlx->texX]);
}
