/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:36:11 by ytouab            #+#    #+#             */
/*   Updated: 2022/11/10 23:52:18 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	ft_map_extension(t_all *all)
{
	size_t	i;

	i = 0;
	if (all->map_file[0] == '.' || ft_strlen(all->map_file) < 5)
		ft_error(all, 2);
	while (all->map_file[i])
		i++;
	i--;
	if (!(all->map_file[i] == 'b' && all->map_file[i - 1] == 'u'
			&& all->map_file[i - 2] == 'c' && all->map_file[i - 3] == '.'))
		ft_error(all, 2);
}

void	check_pos(char c, t_all *all)
{
	if (c == 'N')
	{
		all->size->where = 0;
		direction(all->size);
	}
	if (c == 'E')
	{
		all->size->where = 1;
		direction(all->size);
	}
	if (c == 'S')
	{
		all->size->where = 2;
		direction(all->size);
	}
	if (c == 'W')
	{
		all->size->where = 3;
		direction(all->size);
	}
}

void	ft_map_valid_char(t_all *all, size_t i, size_t nl)
{
	while (all->mapl[i] && nl < 9)
	{
		if (all->mapl[i] == '\n')
			nl++;
		if (nl == 4 || nl == 7)
			;
		else if (all->mapl[i] == '\n'
			&& all->mapl[i + 1] == '\n' && all->mapl[i + 2])
			ft_error(all, 5);
		i++;
	}
	while (all->mapl[i])
	{
		if (all->mapl[i] == '1' || all->mapl[i] == '0' || all->mapl[i] == 'N'
			|| all->mapl[i] == 'S' || all->mapl[i] == 'E' || all->mapl[i] == 'W'
			|| all->mapl[i] == ' ' || all->mapl[i] == '\n')
		{
			check_pos(all->mapl[i], all);
			if (all->mapl[i] == '\n'
				&& all->mapl[i + 1] == '\n' && all->mapl[i + 2])
				ft_error(all, 7);
		}
		else
			ft_error(all, 7);
		i++;
	}
}

void	ft_check_walls(t_all *all)
{
	int	i;

	i = -1;
	while (all->map[++i])
		if ((all->map[i][0] != '1' && all->map[i][0] != ' ')
			|| (all->map[i][ft_strlen(all->map[i]) - 1] != '1'
			&& all->map[i][ft_strlen(all->map[i]) - 1] != ' '))
			ft_error(all, 8);
	i = -1;
	while (++i < (int)ft_strlen(all->map[0]))
		if (all->map[0][i] != '1' && all->map[0][i] != ' ')
			ft_error(all, 8);
	i = -1;
	while (++i < (int)ft_strlen(all->map[ft_arr_len(all->map) - 1]))
		if (all->map[ft_arr_len(all->map) - 1][i] != '1'
		&& all->map[ft_arr_len(all->map) - 1][i] != ' ')
			ft_error(all, 8);
}

void	ft_check_space(t_all *all, int i, int a)
{
	while (all->map[++a])
	{
		i = -1;
		while (all->map[a][++i])
		{
			if (all->map[a][i] == ' ')
			{
				if (all->map[a][i + 1] && (all->map[a][i + 1] != '1'
					&& all->map[a][i + 1] != ' '))
					ft_error(all, 9);
				if (i != 0 && all->map[a][i - 1] && (all->map[a][i - 1] != '1'
					&& all->map[a][i - 1] != ' '))
					ft_error(all, 9);
				if (all->map[a + 1] && all->map[a + 1][i]
					&& (all->map[a + 1][i] != '1' && all->map[a + 1][i] != ' '))
					ft_error(all, 9);
				if (a != 0 && all->map[a - 1] && all->map[a - 1][i]
				&& (all->map[a - 1][i] != '1' && all->map[a - 1][i] != ' '))
					ft_error(all, 9);
			}
		}
	}
}

void	ft_check_zero(t_all *all)
{
	int	i;
	int	a;

	a = -1;
	while (all->map[++a])
	{
		i = -1;
		while (all->map[a][++i])
		{
			if (all->map[a][i] == '0')
			{
				if (!all->map[a][i + 1] || (all->map[a][i + 1] == ' '))
					ft_error(all, 8);
				if (i != 0 && (!all->map[a][i - 1]
					|| all->map[a][i - 1] == ' '))
					ft_error(all, 8);
				if (all->map[a + 1] && (!all->map[a + 1][i]
					|| all->map[a + 1][i] == ' '))
					ft_error(all, 8);
				if (a != 0 && all->map[a - 1] && (!all->map[a - 1][i]
					|| (all->map[a - 1][i] == ' ')))
					ft_error(all, 8);
			}
		}
	}
}
