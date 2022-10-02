#include "../Includes/Cub3d.h"

int	main(int argc, char **argv)
{
	t_all	all;
	t_mlx	mlx;
	t_size	size;
	char	*map[10] = {"111111111111111111",
						"100000000000000001",
						"100000000100000001",
						"100000000000000001",
						"100000000P00000001",
						"100000000000000001",
						"100000000000000001",
						"100000000000000001",
						"111111111111111111"};

	map[9] = NULL;
	(void)argc;
	(void)argv;
	mlx_struct_init(&mlx, &size, &all);
	mlx_main_loop(&all, map);
}
