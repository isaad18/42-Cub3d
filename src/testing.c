#include "../Includes/Cub3d.h"


int	closew(t_all *all)
{
	mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
	exit(0);
}

void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all)
{
	all->mlx = mlx;
	size->posX = 5;
	size->posY = 14;
	size->dirX = -1;
	size->dirY = 0;
	size->planeX = 0;
	size->planeY = 0.66;
	size->win_x = 740;
	size->win_y = 580;
	size->cameraX = 0;
	size->rayDirX = 0;
	size->rayDirY = 0;
	size->mapX = 0;
	size->mapY = 0;
	size->sideDistX = 0;
	size->sideDistY = 0;
	size->deltaDistX = 0;
	size->deltaDistY = 0;
	size->perpWallDist = 0;
	size->stepX = 0;
	size->stepY = 0;
	size->hit = 0;
	size->side = 0;
	size->updown = 0;
	size->lineHeight = 0;
	size->drawStart = 0;
	size->drawEnd = 0;
	all->size = size;
}

int	key(int keycode, t_all *all)
{
	if (keycode == 53){
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
		exit(0);
	}
	if(keycode == 13)
	{
		if(all->map[(int)(all->size->posX + all->size->dirX * all->size->moveSpeed)][(int)(all->size->posY)] != '1') all->size->posX += all->size->dirX * all->size->moveSpeed;
		if(all->map[(int)(all->size->posX)][(int)(all->size->posY + all->size->dirY * all->size->moveSpeed)] != '1') all->size->posY += all->size->dirY * all->size->moveSpeed;
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	if(keycode == 0)
	{
		if(all->map[(int)(all->size->posX + all->size->dirY * all->size->moveSpeed)][(int)(all->size->posY)] != '1') all->size->posX -= all->size->dirY * all->size->moveSpeed;
		if(all->map[(int)(all->size->posX)][(int)(all->size->posY + all->size->dirX * all->size->moveSpeed)] != '1') all->size->posY += all->size->dirX * all->size->moveSpeed;
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	if(keycode == 2)
	{
		if(all->map[(int)(all->size->posX + all->size->dirY * all->size->moveSpeed)][(int)(all->size->posY)] != '1') all->size->posX += all->size->dirY * all->size->moveSpeed;
		if(all->map[(int)(all->size->posX)][(int)(all->size->posY - all->size->dirX * all->size->moveSpeed)] != '1') all->size->posY -= all->size->dirX * all->size->moveSpeed;
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	if(keycode == 1)
	{
		if(all->map[(int)(all->size->posX - all->size->dirX * all->size->moveSpeed)][(int)(all->size->posY)] != '1') all->size->posX -= all->size->dirX * all->size->moveSpeed;
		if(all->map[(int)(all->size->posX)][(int)(all->size->posY - all->size->dirY * all->size->moveSpeed)] != '1') all->size->posY -= all->size->dirY * all->size->moveSpeed;
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	if(keycode == 124)
	{
		double oldDirX = all->size->dirX;
		all->size->dirX = all->size->dirX * cos(-all->size->rotSpeed) - all->size->dirY * sin(-all->size->rotSpeed);
		all->size->dirY = oldDirX * sin(-all->size->rotSpeed) + all->size->dirY * cos(-all->size->rotSpeed);
		double oldPlaneX = all->size->planeX;
		all->size->planeX = all->size->planeX * cos(-all->size->rotSpeed) - all->size->planeY * sin(-all->size->rotSpeed);
		all->size->planeY = oldPlaneX * sin(-all->size->rotSpeed) + all->size->planeY * cos(-all->size->rotSpeed);
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	if(keycode == 123)
	{
		double oldDirX = all->size->dirX;
		all->size->dirX = all->size->dirX * cos(all->size->rotSpeed) - all->size->dirY * sin(all->size->rotSpeed);
		all->size->dirY = oldDirX * sin(all->size->rotSpeed) + all->size->dirY * cos(all->size->rotSpeed);
		double oldPlaneX = all->size->planeX;
		all->size->planeX = all->size->planeX * cos(all->size->rotSpeed) - all->size->planeY * sin(all->size->rotSpeed);
		all->size->planeY = oldPlaneX * sin(all->size->rotSpeed) + all->size->planeY * cos(all->size->rotSpeed);
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	return (0);
}

int	mouse(int x, int y, t_all *all)
{
	static int xx;
	static int yy;
	if (y > yy && (y < all->size->win_y && y > 0) && (x < all->size->win_x && x > 0))
	{
		all->size->updown--;
		all->size->updown--;
		all->size->updown--;
		all->size->updown--;
		all->size->updown--;
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	if (y < yy && (y < all->size->win_y && y > 0) && (x < all->size->win_x && x > 0))
	{
		all->size->updown++;
		all->size->updown++;
		all->size->updown++;
		all->size->updown++;
		all->size->updown++;
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	if (x > xx && (x < all->size->win_x && x > 0) && (y < all->size->win_y && y > 0))
	{
		double oldDirX = all->size->dirX;
		all->size->dirX = all->size->dirX * cos(-all->size->rotSpeed) - all->size->dirY * sin(-all->size->rotSpeed);
		all->size->dirY = oldDirX * sin(-all->size->rotSpeed) + all->size->dirY * cos(-all->size->rotSpeed);
		double oldPlaneX = all->size->planeX;
		all->size->planeX = all->size->planeX * cos(-all->size->rotSpeed) - all->size->planeY * sin(-all->size->rotSpeed);
		all->size->planeY = oldPlaneX * sin(-all->size->rotSpeed) + all->size->planeY * cos(-all->size->rotSpeed);
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	if (x < xx && x > 0 && (y < all->size->win_y && y > 0) && (x < all->size->win_x && x > 0))
	{
		double oldDirX = all->size->dirX;
		all->size->dirX = all->size->dirX * cos(all->size->rotSpeed) - all->size->dirY * sin(all->size->rotSpeed);
		all->size->dirY = oldDirX * sin(all->size->rotSpeed) + all->size->dirY * cos(all->size->rotSpeed);
		double oldPlaneX = all->size->planeX;
		all->size->planeX = all->size->planeX * cos(all->size->rotSpeed) - all->size->planeY * sin(all->size->rotSpeed);
		all->size->planeY = oldPlaneX * sin(all->size->rotSpeed) + all->size->planeY * cos(all->size->rotSpeed);
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	xx = x;
	yy = y;
	return (0);
}

void	mlx_main_loop(t_all *all, char *map[10])
{
	(void)map;
	all->mlx->mlx = mlx_init();
	all->mlx->mlx_win = mlx_new_window(all->mlx->mlx, all->size->win_x, all->size->win_y, "Cub3d");
	print_plz(all, map);
	mlx_hook(all->mlx->mlx_win, 2, 1L<<0, key, all);
	mlx_hook(all->mlx->mlx_win, 6, 1L<<6, mouse, all);
	mlx_hook(all->mlx->mlx_win, 17, 1L<<5, closew, all);
	mlx_loop(all->mlx->mlx);
}

void	drawall(t_all *all, int **buffer)
{
	int	i;
	int	j;
	int	w;
	int	b;
	int	h;
	void	*img;
	int	*texture;

	i = 0;
	j = 0;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	img = mlx_new_image(all->mlx->mlx, all->size->win_x, all->size->win_y);
	texture = (int *)mlx_get_data_addr(img, &b, &w, &h);
	while (j < all->size->win_y)
	{
		i = 0;
		while (i < all->size->win_x)
		{
			texture[j * all->size->win_x + i] = buffer[j][i];
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->mlx_win, img, 0, 0);
}

int print_plz(t_all *all, char *map[10])
{
	double time = 0;
	double oldTime = 0;

	time = clock();
	int	*text;
	void	*tex;
	int	*text2;
	void	*tex2;
	int texX;
	int texY;
	int w = 0;
	int h = 0;
	int b = 0;
	int ii = 0;
	tex = mlx_xpm_file_to_image(all->mlx->mlx, "Imgs/new2.xpm", &w, &h);
	text = (int *)mlx_get_data_addr(tex, &b, &h, &w);
	tex2 = mlx_xpm_file_to_image(all->mlx->mlx, "Imgs/new1.xpm", &w, &h);
	text2 = (int *)mlx_get_data_addr(tex2, &b, &h, &w);
	int **buffer;
	buffer = malloc(sizeof(int *) * all->size->win_y);
	int xx = 0;
	while (xx < all->size->win_y)
	{
		buffer[xx] = malloc(sizeof(int) * all->size->win_x);
		xx++;
	}
	for (int x = 0; x < all->size->win_x; x++)
	{
		all->size->cameraX = 2 * x / (double)all->size->win_x - 1;
		all->size->rayDirX = all->size->dirX + all->size->planeX * all->size->cameraX;
		all->size->rayDirY = all->size->dirY + all->size->planeY * all->size->cameraX;
		all->size->mapX = (int)all->size->posX;
		all->size->mapY = (int)all->size->posY;
		all->size->deltaDistX = (all->size->rayDirX == 0) ? 1e30 : fabs(1 / all->size->rayDirX);
		all->size->deltaDistY = (all->size->rayDirY == 0) ? 1e30 : fabs(1 / all->size->rayDirY);
		all->size->hit = 0;
		if(all->size->rayDirX < 0)
		{
			all->size->stepX = -1;
			all->size->sideDistX = (all->size->posX - all->size->mapX) * all->size->deltaDistX;
		}
		else
		{
			all->size->stepX = 1;
			all->size->sideDistX = (all->size->mapX + 1.0 - all->size->posX) * all->size->deltaDistX;
		}
		if(all->size->rayDirY < 0)
		{
			all->size->stepY = -1;
			all->size->sideDistY = (all->size->posY - all->size->mapY) * all->size->deltaDistY;
		}
		else
		{
			all->size->stepY = 1;
			all->size->sideDistY = (all->size->mapY + 1.0 - all->size->posY) * all->size->deltaDistY;
		}
		while(all->size->hit == 0)
		{
			if(all->size->sideDistX < all->size->sideDistY)
			{
			  all->size->sideDistX += all->size->deltaDistX;
			  all->size->mapX += all->size->stepX;
			  all->size->side = 0;
			}
			else
			{
			  all->size->sideDistY += all->size->deltaDistY;
			  all->size->mapY += all->size->stepY;
			  all->size->side = 1;
			}
			if (map[all->size->mapX][all->size->mapY] != '0' && map[all->size->mapX][all->size->mapY] != 'P')
				all->size->hit = 1;
		}
		if(all->size->side == 0)
			all->size->perpWallDist = (all->size->sideDistX - all->size->deltaDistX);
		else
			all->size->perpWallDist = (all->size->sideDistY - all->size->deltaDistY);
		int lineHeight = (int)(all->size->win_y / all->size->perpWallDist);
		int drawStart = -lineHeight / 2 + ((all->size->win_y / 2) + all->size->updown);
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + ((all->size->win_y / 2) + all->size->updown);
		if(drawEnd >= all->size->win_y)
			drawEnd = all->size->win_y - 1;
		double wallX;
		if(all->size->side == 0 && map[(int)all->size->mapX][(int)all->size->mapY] == '1')
		{
			wallX = all->size->posY + all->size->perpWallDist * all->size->rayDirY;
			ii = 1;
		}
		else
		{
			wallX = all->size->posX + all->size->perpWallDist * all->size->rayDirX;
			ii = 2;
		}
		int iii = (int)wallX;
		wallX = (double)wallX - (int)iii;
		texX = (int)(wallX * (double)64);
		if(all->size->side == 0 && all->size->rayDirX > 0)
		{
			texX = 64 - texX - 1;
		}
		if(all->size->side == 1 && all->size->rayDirY < 0)
		{
			texX = 64 - texX - 1;
		}
		double step = 1.0 * 64 / lineHeight;
		double texPos = (drawStart - ((all->size->win_y / 2) + all->size->updown) + lineHeight / 2) * step;
		for(int y = drawStart; y < drawEnd; y++)
		{
			texY = (int)texPos & (64 - 1);
			texPos += step;
			int color;
			if (ii == 1)
				color = mlx_get_color_value(all->mlx->mlx, text[(64 * texY) + texX]);
			else
				color = mlx_get_color_value(all->mlx->mlx, text2[(64 * texY) + texX]);
			buffer[y][x] = color;
		}
		for(int y = 0; y < drawStart; y++)
		{
			if (drawStart < 0 || drawStart > drawEnd)
				break;
			buffer[y][x] = 0x87CEEB;
		}
		for(int y = drawEnd; y < all->size->win_y; y++)
		{
			if (drawEnd < 0 || drawEnd < drawStart)
				break;
			buffer[y][x] = 0x964B00;
		}
		int j = 0;
		while (j < all->size->win_y)
		{
			if (buffer[j][x] == 0 && all->size->updown > 0 && (j < drawStart || j > drawEnd))
				buffer[j][x] = 0x87CEEB;
			if (buffer[j][x] == 0 && all->size->updown < 0 && (j < drawStart || j > drawEnd))
				buffer[j][x] = 0x964B00;
			j++;
		}
	}


	printf("%f      %f\n", all->size->planeX, all->size->planeY);
	printf("%f      %f\n", all->size->dirX, all->size->dirY);
	printf("________________________________________\n");


	drawall(all, buffer);
	oldTime = time;
	time = clock();
	double frameTime = (time - oldTime) / 500900.0;
	all->size->moveSpeed = frameTime * 5.0;
	all->size->rotSpeed = frameTime * 3.0;
	return (0);
}