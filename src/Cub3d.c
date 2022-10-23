#include "../Includes/Cub3d.h"

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
		ft_arr_print(all.map);
		mlx_main_loop(&all, all.map);
	}
	else
		ft_error(&all, 1);
}

