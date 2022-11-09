/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:36:11 by ytouab            #+#    #+#             */
/*   Updated: 2022/11/09 23:17:48 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	ft_quit(t_all *all)
{
	int	i;
	int	excode;

	i = -1;
	(void)i;
	excode = all->exit;
	// if (all->mlx->mlx_win)
	// 	mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
	// if (all->mlx->tex)
	// 	mlx_destroy_image(all->mlx->mlx, all->mlx->tex);
	// if (all->mlx->tex2)
	// 	mlx_destroy_image(all->mlx->mlx, all->mlx->tex2);
	// if (all->mlx->img)
	// 	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	// if (all->mlx->buffer)
	// 	while (++i < all->size->win_y)
	// 		free(all->mlx->buffer[i]);
	// free(all->mlx->buffer);
	exit(excode);
}

void	ft_error(t_all *all, int error)
{
	all->exit = error;
	if (error != 0)
		ft_putstr_fd(R"Error: ", 2);
	if (error == 1)
		ft_putstr_fd(Y"Wrong number of arguments\n", 2);
	else if (error == 2)
		ft_putstr_fd(Y"Invalid map extension\n", 2);
	else if (error == 3)
		ft_putstr_fd(Y"File reading failed\n", 2);
	else if (error == 4)
		ft_putstr_fd(Y"Memory allocation failed\n", 2);
	else if (error == 5)
		ft_putstr_fd(Y"Invalid Map\n", 2);
	else if (error == 6)
		ft_putstr_fd(Y"Invalid Color\n", 2);
	else if (error == 7)
		ft_putstr_fd(Y"Invalid Chars in Map\n", 2);
	ft_quit(all);
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
	ft_arr_print(all->textures);
	ft_arr_print(all->colors);
	ft_arr_print(all->map);
	ft_color_parse(all);
	ft_map_valid_char(all);
	// ft_map_valid_char(all);
	// if (!all->c || all->e != 1 || all->p != 1)
	// 	ft_error(all, all);
	// ft_check_rect(all, all);
	// ft_check_walls(all, all);
}

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

void	ft_color_chars_checker(t_all *all, size_t i, size_t a, int comma)
{
	if (all->colors[a][0] != 'F' || all->colors[1][0] != 'C'
		|| all->colors[0][1] != ' ' || all->colors[1][1] != ' ')
		ft_error(all, 6);
	while (a < 2)
	{
		comma = 0;
		i = 2;
		while (all->colors[a][i])
		{
			if (!ft_isdigit(all->colors[a][i]))
				ft_error(all, 6);
			if (ft_atoi_index(all, all->colors[a], i, 6) > 255
				|| ft_atoi_index(all, all->colors[a], i, 6) < 0)
				ft_error(all, 6);
			while (all->colors[a][i] && ft_isdigit(all->colors[a][i]))
				i++;
			if (all->colors[a][i] && all->colors[a][i] == ',')
				comma++;
			if (all->colors[a][i] &&
				(all->colors[a][i] != ',' || !ft_isdigit(all->colors[a][++i])))
				ft_error(all, 6);
		}
		if (++a && comma != 2)
			ft_error(all, 6);
	}
}

char	*ft_rgb_to_hex(t_all *all, char *rgb, size_t i)
{
	char	*color;
	int		tmp;

	color = ft_strdup("");
	tmp = 255;
	while (rgb[i])
	{
		tmp = ft_atoi_index(all, rgb, i, 6);
		color = ft_strjoin(color, ft_convert_base(ft_itoa(tmp), DEC, HEX));
		while (rgb[i] && ft_isdigit(rgb[i]))
			i++;
		if (rgb[i] && rgb[i] == ',')
			i++;
	}
	return (color);
}

void	ft_color_parse(t_all *all)
{
	char	*fc;
	char	*cc;

	ft_color_chars_checker(all, 2, 0, 0);
	fc = ft_convert_base(ft_rgb_to_hex(all, all->colors[0], 2), HEX, DEC);
	cc = ft_convert_base(ft_rgb_to_hex(all, all->colors[1], 2), HEX, DEC);
	all->mlx->Fcolor = ft_atoi_index(all, fc, 0, 6);
	all->mlx->Ccolor = ft_atoi_index(all, cc, 0, 6);
	free(fc);
	free(cc);
}

void	ft_map_valid_char(t_all *all)
{
	size_t	i;
	size_t	nl;

	i = 0;
	nl = 0;
	while (all->mapl[i] && nl < 9)
	{
		// if ((nl == 4 && all->mapl[i] == '\n' && all->mapl[i + 1] != '\n')
		// 	|| (nl == 7 && all->mapl[i] == '\n' && all->mapl[i + 1] != '\n'))
		// 	ft_error(all, 5);
		if (all->mapl[i] == '\n')
			nl++;
		i++;
	}
	while (all->mapl[i])
	{
		if (all->mapl[i] == '1' || all->mapl[i] == '0' || all->mapl[i] == 'N'
			|| all->mapl[i] == 'S' || all->mapl[i] == 'E' || all->mapl[i] == 'W'
			|| all->mapl[i] == ' ' || all->mapl[i] == '\n')
		{
			if (all->mapl[i] == '\n'
				&& all->mapl[i + 1] == '\n' && all->mapl[i + 2])
				ft_error(all, 7);
		}
		else
			ft_error(all, 7);
		i++;
	}
}

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
