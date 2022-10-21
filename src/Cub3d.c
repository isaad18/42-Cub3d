#include "../Includes/Cub3d.h"

int	main(int argc, char **argv)
{
	t_all	all;
	t_mlx	mlx;
	t_size	size;
	char	**map;


	map = malloc(sizeof(char *) * 10);
	map[0] = "1111111111111111111";
	map[1] = "1000000000000000001";
	map[2] = "1010111111111111111";
	map[3] = "1010100000000000001";
	map[4] = "1110111110010000001";
	map[5] = "101000000001000P001";
	map[6] = "1001111000010000001";
	map[7] = "1000000000000000001";
	map[8] = "1111111111111111111";
	map[9] = NULL;
	(void)argc;
	(void)argv;
	mlx_struct_init(&mlx, &size, &all);
	all.map = map;
	mlx_main_loop(&all, map);
}

