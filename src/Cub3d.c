#include "../Includes/Cub3d.h"

int	main(int argc, char **argv)
{
	t_all	all;
	t_mlx	mlx;
	t_size	size;

	if (argc == 2)
	{
		mlx_struct_init(&mlx, &size, &all);
		all.map_file = ft_strdup(argv[1]);
		ft_map_checker(&all);
		mlx_main_loop(&all, all.map);
	}
	else
		ft_error(&all);
}

