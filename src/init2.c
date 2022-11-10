/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:24:52 by isaad             #+#    #+#             */
/*   Updated: 2022/11/11 00:02:38 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	where_0(t_size *size)
{
	if (size->where == 0)
	{
		size->dirx = -1;
		size->diry = 0;
		size->planex = 0;
		size->planey = 0.66;
	}
}

void	direction(t_size *size)
{
	where_0(size);
	if (size->where == 1)
	{
		size->dirx = 0;
		size->diry = 1;
		size->planex = 0.66;
		size->planey = 0;
	}
	else if (size->where == 2)
	{
		size->dirx = 1;
		size->diry = 0;
		size->planex = 0;
		size->planey = -0.66;
	}
	else if (size->where == 3)
	{
		size->dirx = 0;
		size->diry = -1;
		size->planex = -0.66;
		size->planey = 0;
	}
}

void	check_w(char c, t_all *all, int *detector)
{
	if (c == 'W')
	{
		all->size->where = 3;
		direction(all->size);
		(*detector)++;
	}
	if (*detector > 1)
		ft_error(all, 7);
}

void	check_pos(char c, t_all *all)
{
	static int	detector;

	if (c == 'N')
	{
		all->size->where = 0;
		direction(all->size);
		detector++;
	}
	if (c == 'E')
	{
		all->size->where = 1;
		direction(all->size);
		detector++;
	}
	if (c == 'S')
	{
		all->size->where = 2;
		direction(all->size);
		detector++;
	}
	check_w(c, all, &detector);
}
