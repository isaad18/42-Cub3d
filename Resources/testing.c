#include "../Includes/Cub3d.h"

int	closew(t_all *all)
{
	mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
	exit(0);
}

void	print_pixels(int color, t_all *all, int x, int y)
{
	int i = y;
	int j = x;

	while (i < y + 50)
	{
		j = x;
		while (j < x + 50)
		{
			mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, j, i, color);
			j++;
		}
		i++;
	}
}

int	keys(int keycode, t_all *all)
{
	if (keycode == 53)
	{
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
		exit(0);
	}
	if (keycode == 0)
	{
		print_pixels(0x000000FF, all, all->size->Pl_x, all->size->Pl_y);
		all->size->Pl_x--;
		all->size->Pl_x--;
		all->size->Pl_x--;
		print_pixels(0x00F0FF0F, all, all->size->Pl_x, all->size->Pl_y);
		print_pixels(0x00F0FF0F, all, all->size->Pl_x, all->size->Pl_y);
	}
	if (keycode == 13)
	{
		print_pixels(0x000000FF, all, all->size->Pl_x, all->size->Pl_y);
		all->size->Pl_y--;
		all->size->Pl_y--;
		all->size->Pl_y--;
		print_pixels(0x00F0FF0F, all, all->size->Pl_x, all->size->Pl_y);
	}
	if (keycode == 1)
	{
		print_pixels(0x000000FF, all, all->size->Pl_x, all->size->Pl_y);
		all->size->Pl_y++;
		all->size->Pl_y++;
		all->size->Pl_y++;
		print_pixels(0x00F0FF0F, all, all->size->Pl_x, all->size->Pl_y);
	}
	if (keycode == 2)
	{
		print_pixels(0x000000FF, all, all->size->Pl_x, all->size->Pl_y);
		all->size->Pl_x++;
		all->size->Pl_x++;
		all->size->Pl_x++;
		print_pixels(0x00F0FF0F, all, all->size->Pl_x, all->size->Pl_y);
	}
	return (3);
}

void	print_map(t_all *all, char *map[10])
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	while (map[i])
	{
		j = 0;
		x = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				print_pixels(0x00FF0F0F, all, x, y);
			else if (map[i][j] == '0')
				print_pixels(0x000000FF, all, x, y);
			else if (map[i][j] == 'P')
			{
				print_pixels(0x00F0FF0F, all, x, y);
			}
			j++;
			x += 51;
		}
		y += 51;
		i++;
	}
}

void	print_ray_pixels(t_all *all, double counter, int new_mid)
{
	double i = all->size->mid_y;
	double pixels = (10000000000 / (counter * 100000000));

	printf("%f\n", pixels);
	while (i > all->size->mid_y - pixels)
	{
		mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, new_mid, i, 0x00FF00FF);
		i -= 0.1;
	}
	i = all->size->mid_y;
	while (i < all->size->mid_y + pixels)
	{
		mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, new_mid, i, 0x00FF00FF);
		i += 0.1;
	}
}

void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all)
{
	all->mlx = mlx;
	size->Pl_x = 9;
	size->Pl_y = 4;
	size->win_x = 1500;
	size->mid_x = 750;
	size->win_y = 850;
	size->mid_y = 425;
	size->ratio = 850;
	size->cam_x = 0;
	size->cam_y = -1;
	size->ray_x = 0.001;
	size->ray_y = 0.001;
	size->ray_x2 = -0.001;
	size->ray_y2 = -0.001;
	all->size = size;
}

double	get_dis(t_all *all, double x, double y)
{
	double	dis;

	dis = sqrt(((x - all->size->Pl_x) * (x - all->size->Pl_x)) + ((y - all->size->Pl_y) * (y - all->size->Pl_y)));
	return (dis);
}

void	check_ray(t_all *all, char *map[10], int new_mid)
{
	double x = all->size->Pl_x;
	double y = all->size->Pl_y;
	int counter = 0;

	while (map[(int)y][(int)x] != '1')
	{
		x += all->size->cam_x;
		y += all->size->cam_y;
		counter++;
	}
	print_ray_pixels(all, get_dis(all, x, y), new_mid);
}

void	print_3d(t_all *all, char *map[10])
{
	while (all->size->cam_x < 1)
	{
		// check_ray(all, map, all->size->mid_x);
		all->size->cam_x += all->size->ray_x;
		all->size->cam_y += all->size->ray_y;
		all->size->mid_x++;
	}
	all->size->mid_x = all->size->win_x;
	while (all->size->cam_x > -1)
	{
		check_ray(all, map, all->size->mid_x);
		all->size->cam_x += all->size->ray_x2;
		all->size->cam_y += all->size->ray_y2;
		all->size->mid_x--;
	}
	// while (all->size->cam_x > -1)
	// {
	// 	check_ray(all, map, all->size->mid_x);
	// 	all->size->cam_x -= all->size->ray_x;
	// 	all->size->cam_y -= all->size->ray_y;
	// 	all->size->mid_x--;
	// }
}

void	mlx_main_loop(t_all *all, char *map[10])
{
	(void)map;
	all->mlx->mlx = mlx_init();
	all->mlx->mlx_win = mlx_new_window(all->mlx->mlx, all->size->win_x, all->size->win_y, "Cub3d");
	print_3d(all, map);
	mlx_hook(all->mlx->mlx_win, 17, 1L<<5, closew, all);
	mlx_loop(all->mlx->mlx);
}