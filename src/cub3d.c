/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:33:18 by ytouab            #+#    #+#             */
/*   Updated: 2022/11/10 13:40:07 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

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
