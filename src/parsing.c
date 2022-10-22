/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:36:11 by ytouab            #+#    #+#             */
/*   Updated: 2022/10/22 19:28:36 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Cub3d.h"

void	ft_error(t_all *all)
{
	(void)all;
	ft_putstr_fd("ERROR\n", 2);
	exit (1);
}

void	ft_read(int fd, t_all *all)
{
	char	*buffer;
	char	*mapline;
	int		rd;

	rd = 1;
	mapline = ft_strdup("");
	buffer = malloc(2);
	mapline[0] = 0;
	buffer[1] = 0;
	while (rd == 1)
	{
		rd = read(fd, &buffer[0], 1);
		if (rd == -1)
		{
			free(buffer);
			free(mapline);
			ft_error(all);
		}
		mapline = ft_strjoin(mapline, buffer);
	}
	free(buffer);
	all->mapl = mapline;
}

void	ft_map_checker(t_all *all)
{
	int	fd;

	ft_map_extension(all);
	fd = open(all->map_file, O_RDONLY);
	ft_read(fd, all);
	close(fd);
	// ft_map_valid_char(all, all);
	// if (!all->c || all->e != 1 || all->p != 1)
	// 	ft_error(all, all);
	ft_split(all->mapl, all);
	// ft_check_rect(all, all);
	// ft_check_walls(all, all);
}

void	ft_map_extension(t_all *all)
{
	size_t	i;

	i = 0;
	if (all->map_file[0] == '.' || ft_strlen(all->map_file) < 5)
		ft_error(all);
	while (all->map_file[i])
		i++;
	i--;
	if (!(all->map_file[i] == 'b' && all->map_file[i - 1] == 'u'
			&& all->map_file[i - 2] == 'c' && all->map_file[i - 3] == '.'))
		ft_error(all);
}

// void	ft_map_valid_char(t_all *all)
// {
// 	size_t	i;

// 	i = 0;
// 	while (all->mapl[i])
// 	{
// 		if (all->mapl[i] == '1' || all->mapl[i] == '0' || all->mapl[i] == 'C'
// 			|| all->mapl[i] == 'E' || all->mapl[i] == 'P' || all->mapl[i] == '\n'
// 			|| all->mapl[i] == 'X')
// 		{
// 			if (all->mapl[i] == 'E')
// 				all->e++;
// 			else if (all->mapl[i] == 'C')
// 				all->c++;
// 			else if (all->mapl[i] == 'P')
// 				all->p++;
// 			else if (all->mapl[i] == '\n'
// 				&& all->mapl[i + 1] == '\n' && all->mapl[i + 2])
// 				ft_error(all);
// 		}
// 		else
// 			ft_error(all, all);
// 		i++;
// 	}
// }

// void	ft_check_rect(t_all *all)
// {
// 	size_t	i;

// 	i = 0;
// 	all->width = ft_strlen(all->map[i]);
// 	while (all->map[i])
// 	{
// 		if (all->width != ft_strlen(all->map[i]))
// 			ft_error(all, all);
// 		i++;
// 	}
// }

// void	ft_check_walls(t_all *all)
// {
// 	size_t	i;

// 	i = 0;
// 	while (all->map[i])
// 	{
// 		if (all->map[i][0] != '1' || all->map[i][all->width - 1] != '1')
// 			ft_error(all, all);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < all->width)
// 	{
// 		if (all->map[0][i] != '1' || all->map[all->height - 1][i] != '1')
// 			ft_error(all, all);
// 		i++;
// 	}
// }
