/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MKcmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:26:23 by isaad             #+#    #+#             */
/*   Updated: 2022/11/07 20:34:26 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Cub3d.h"

int	key(int keycode, t_all *all)
{
	if (keycode == 53)
		ft_quit(all);
	if (keycode == 13)
		key13(all);
	if (keycode == 0)
		key0(all);
	if (keycode == 2)
		key2(all);
	if (keycode == 1)
		key1(all);
	if (keycode == 124)
		key124(all);
	if (keycode == 123)
		key123(all);
	return (0);
}

int	mouse(int x, int y, t_all *all)
{
	static int	xx;
	static int	yy;

	if (y > yy && (y < all->size->win_y && y > 0) && \
	(x < all->size->win_x && x > 0))
		keydown(all);
	if (y < yy && (y < all->size->win_y && y > 0) && \
	(x < all->size->win_x && x > 0))
		keyup(all);
	if (x > xx && (x < all->size->win_x && x > 0) && \
	(y < all->size->win_y && y > 0))
		key124(all);
	if (x < xx && x > 0 && (y < all->size->win_y && y > 0) && \
	(x < all->size->win_x && x > 0))
		key123(all);
	xx = x;
	yy = y;
	return (0);
}
