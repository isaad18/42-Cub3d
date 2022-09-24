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
				all->size->Pl_x = x;
				all->size->Pl_y = y;
				print_pixels(0x00F0FF0F, all, x, y);
			}
			j++;
			x += 51;
		}
		y += 51;
		i++;
	}
}

void	mlx_main_loop(t_all *all, char *map[10])
{
	all->mlx->mlx = mlx_init();
	all->mlx->mlx_win = mlx_new_window(all->mlx->mlx, all->size->win_x, all->size->win_y, "Cub3d");
	print_map(all, map);
	mlx_hook(all->mlx->mlx_win, 17, 1L<<5, closew, all);
	mlx_hook(all->mlx->mlx_win, 02, 1L<<2, keys, all);
	mlx_loop(all->mlx->mlx);
}

void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all)
{
	all->mlx = mlx;
	size->win_x = 1500;
	size->win_y = 850;
	all->size = size;
}
