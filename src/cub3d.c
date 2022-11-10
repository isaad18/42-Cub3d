/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:33:18 by ytouab            #+#    #+#             */
/*   Updated: 2022/11/10 22:26:33 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

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
			ft_error(all, 3);
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
	all->splmap = ft_split(all->mapl, all);
	all->textures = ft_arr_dup(all->splmap, 0, 4);
	all->colors = ft_arr_dup(all->splmap, 4, 2);
	all->map = ft_arr_dup(all->splmap, 6, ft_arr_len(all->splmap) - 6);
	ft_color_parse(all);
	ft_map_valid_char(all, 0, 0);
	ft_check_walls(all);
	ft_check_space(all, -1, -1);
	ft_check_zero(all);
	ft_texture(all);
}

int	main(int argc, char **argv)
{
	t_all	all;
	t_mlx	mlx;
	t_size	size;

	mlx_struct_init(&mlx, &size, &all);
	if (argc == 2)
	{
		all.map_file = ft_strdup(argv[1]);
		ft_map_checker(&all);
		mlx_main_loop(&all, all.map);
	}
	else
		ft_error(&all, 1);
}
