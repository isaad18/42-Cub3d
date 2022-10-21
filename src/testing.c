#include "../Includes/Cub3d.h"


int	closew(t_all *all)
{
	mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
	exit(0);
}

void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all)
{
	mlx->Ccolor = 0x87CEEB;
	mlx->Fcolor = 0x964B00;
	all->mlx = mlx;
	size->where = 3;
	size->posX = 5;
	size->posY = 14;
	if (size->where == 0)
	{
		size->dirX = -1;
		size->dirY = 0;
		size->planeX = 0;
		size->planeY = 0.66;
	}
	else if (size->where == 1)
	{
		size->dirX = 0;
		size->dirY = 1;
		size->planeX = 0.66;
		size->planeY = 0;
	}
	else if (size->where == 2)
	{
		size->dirX = 1;
		size->dirY = 0;
		size->planeX = 0;
		size->planeY = -0.66;
	}
	else if (size->where == 3)
	{
		size->dirX = 0;
		size->dirY = -1;
		size->planeX = -0.66;
		size->planeY = 0;
	}
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

void	key13(t_all *all)
{
	if(all->map[(int)(all->size->posX + all->size->dirX * all->size->moveSpeed)][(int)\
	(all->size->posY)] != '1') all->size->posX += all->size->dirX * all->size->moveSpeed;
	if(all->map[(int)(all->size->posX)][(int)(all->size->posY + all->size->dirY * \
	all->size->moveSpeed)] != '1') all->size->posY += all->size->dirY * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key0(t_all *all)
{
	if(all->map[(int)(all->size->posX - all->size->dirY * all->size->moveSpeed)][(int)\
	(all->size->posY)] != '1') all->size->posX -= all->size->dirY * all->size->moveSpeed;
	if(all->map[(int)(all->size->posX)][(int)(all->size->posY + all->size->dirX * \
	all->size->moveSpeed)] != '1') all->size->posY += all->size->dirX * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key1(t_all *all)
{
	if(all->map[(int)(all->size->posX - all->size->dirX * all->size->moveSpeed)][(int)\
	(all->size->posY)] != '1') all->size->posX -= all->size->dirX * all->size->moveSpeed;
	if(all->map[(int)(all->size->posX)][(int)(all->size->posY - all->size->dirY * \
	all->size->moveSpeed)] != '1') all->size->posY -= all->size->dirY * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key2(t_all *all)
{
	if(all->map[(int)(all->size->posX + all->size->dirY * all->size->moveSpeed)][(int)\
	(all->size->posY)] != '1') all->size->posX += all->size->dirY * all->size->moveSpeed;
	if(all->map[(int)(all->size->posX)][(int)(all->size->posY - all->size->dirX * \
	all->size->moveSpeed)] != '1') all->size->posY -= all->size->dirX * all->size->moveSpeed;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key123(t_all *all)
{
	double oldDirX = all->size->dirX;
	double oldPlaneX = all->size->planeX;

	all->size->dirX = all->size->dirX * cos(all->size->rotSpeed) - \
	all->size->dirY * sin(all->size->rotSpeed);
	all->size->dirY = oldDirX * sin(all->size->rotSpeed) + all->size->dirY\
	 * cos(all->size->rotSpeed);
	all->size->planeX = all->size->planeX * cos(all->size->rotSpeed)\
	 - all->size->planeY * sin(all->size->rotSpeed);
	all->size->planeY = oldPlaneX * sin(all->size->rotSpeed)\
	 + all->size->planeY * cos(all->size->rotSpeed);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	key124(t_all *all)
{
	double oldDirX = all->size->dirX;
	double oldPlaneX = all->size->planeX;

	all->size->dirX = all->size->dirX * cos(-all->size->rotSpeed) - \
	all->size->dirY * sin(-all->size->rotSpeed);
	all->size->dirY = oldDirX * sin(-all->size->rotSpeed) + all->size->dirY\
	 * cos(-all->size->rotSpeed);
	all->size->planeX = all->size->planeX * cos(-all->size->rotSpeed) - \
	all->size->planeY * sin(-all->size->rotSpeed);
	all->size->planeY = oldPlaneX * sin(-all->size->rotSpeed) + \
	all->size->planeY * cos(-all->size->rotSpeed);
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	keyup(t_all *all)
{
	all->size->updown += 7;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

void	keydown(t_all *all)
{
	all->size->updown -= 7;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	print_plz(all, all->map);
}

int	key(int keycode, t_all *all)
{
	if (keycode == 53){
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
		exit(0);
	}
	if(keycode == 13)
		key13(all);
	if(keycode == 0)
		key0(all);
	if(keycode == 2)
		key2(all);
	if(keycode == 1)
		key1(all);
	if(keycode == 124)
		key124(all);
	if(keycode == 123)
		key123(all);
	return (0);
}

int	mouse(int x, int y, t_all *all)
{
	static int xx;
	static int yy;

	if (y > yy && (y < all->size->win_y && y > 0) && (x < all->size->win_x && x > 0))
		keydown(all);
	if (y < yy && (y < all->size->win_y && y > 0) && (x < all->size->win_x && x > 0))
		keyup(all);
	if (x > xx && (x < all->size->win_x && x > 0) && (y < all->size->win_y && y > 0))
		key124(all);
	if (x < xx && x > 0 && (y < all->size->win_y && y > 0) && (x < all->size->win_x && x > 0))
		key123(all);
	xx = x;
	yy = y;
	return (0);
}

void	mlx_main_loop(t_all *all, char *map[10])
{
	all->mlx->mlx = mlx_init();
	all->mlx->mlx_win = mlx_new_window(all->mlx->mlx, all->size->win_x, all->size->win_y, "Cub3d");
	initImgs(all);
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

void	fill_the_void(t_all *all, int y, int x)
{
	while (y < all->mlx->drawStart)
	{
		if (all->mlx->drawStart < 0 || all->mlx->drawStart > all->mlx->drawEnd)
			break;
		all->mlx->buffer[y][x] = all->mlx->Ccolor;
		y++;
	}
	y = all->mlx->drawEnd;
	while (y < all->size->win_y)
	{
		if (all->mlx->drawEnd < 0 || all->mlx->drawEnd < all->mlx->drawStart)
			break;
		all->mlx->buffer[y][x] = all->mlx->Fcolor;
		y++;
	}
	y = 0;
	while (y < all->size->win_y)
	{
		if (all->mlx->buffer[y][x] == 0 && all->size->updown > 0 && (y < all->mlx->drawStart || y > all->mlx->drawEnd))
			all->mlx->buffer[y][x] = all->mlx->Ccolor;
		if (all->mlx->buffer[y][x] == 0 && all->size->updown < 0 && (y < all->mlx->drawStart || y > all->mlx->drawEnd))
			all->mlx->buffer[y][x] = all->mlx->Fcolor;
		y++;
	}
}

void	getAndFillWalls(t_all *all, int y, int x, int ii)
{
	all->size->wallX = (double)all->size->wallX - (int)all->size->wallX;
	all->mlx->texX = (int)(all->size->wallX * (double)64);
	if(all->size->side == 0 && all->size->rayDirX > 0)
		all->mlx->texX = 64 - all->mlx->texX - 1;
	if(all->size->side == 1 && all->size->rayDirY < 0)
		all->mlx->texX = 64 - all->mlx->texX - 1;
	all->size->step = 1.0 * 64 / all->mlx->lineHeight;
	all->size->texPos = (all->mlx->drawStart - ((all->size->win_y / 2) + all->size->updown) + all->mlx->lineHeight / 2) * all->size->step;
	y = all->mlx->drawStart;
	while (y < all->mlx->drawEnd)
	{
		all->mlx->texY = (int)all->size->texPos & (64 - 1);
		all->size->texPos += all->size->step;
		if (ii == 1)
			all->size->color = mlx_get_color_value(all->mlx->mlx, all->mlx->text[(64 * all->mlx->texY) + all->mlx->texX]);
		else
			all->size->color = mlx_get_color_value(all->mlx->mlx, all->mlx->text2[(64 * all->mlx->texY) + all->mlx->texX]);
		all->mlx->buffer[y][x] = all->size->color;
		y++;
	}
}

void	initDir(t_all *all)
{
	if(all->size->rayDirX < 0)
	{
		all->size->stepX = -1;
		all->size->sideDistX = (all->size->posX - \
		all->size->mapX) * all->size->deltaDistX;
	}
	else
	{
		all->size->stepX = 1;
		all->size->sideDistX = (all->size->mapX + 1.0 - \
		all->size->posX) * all->size->deltaDistX;
	}
	if(all->size->rayDirY < 0)
	{
		all->size->stepY = -1;
		all->size->sideDistY = (all->size->posY - \
		all->size->mapY) * all->size->deltaDistY;
	}
	else
	{
		all->size->stepY = 1;
		all->size->sideDistY = (all->size->mapY + 1.0 - \
		all->size->posY) * all->size->deltaDistY;
	}
}

void	initDrawing(t_all *all, int x)
{
	all->size->cameraX = 2 * x / (double)all->size->win_x - 1;
	all->size->rayDirX = all->size->dirX + all->size->planeX * all->size->cameraX;
	all->size->rayDirY = all->size->dirY + all->size->planeY * all->size->cameraX;
	all->size->mapX = (int)all->size->posX;
	all->size->mapY = (int)all->size->posY;
	all->size->deltaDistX = (all->size->rayDirX == 0) ? 1e30 : fabs(1 / all->size->rayDirX);
	all->size->deltaDistY = (all->size->rayDirY == 0) ? 1e30 : fabs(1 / all->size->rayDirY);
	all->size->hit = 0;
}

void	getWallHit(t_all *all, char **map)
{
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
}

void	getDrawPos(t_all *all, char **map, int *ii)
{
	if(all->size->side == 0)
		all->size->perpWallDist = (all->size->sideDistX - all->size->deltaDistX);
	else
		all->size->perpWallDist = (all->size->sideDistY - all->size->deltaDistY);
	all->mlx->lineHeight = (int)(all->size->win_y / all->size->perpWallDist);
	all->mlx->drawStart = -all->mlx->lineHeight / 2 + ((all->size->win_y / 2) + all->size->updown);
	if(all->mlx->drawStart < 0)
		all->mlx->drawStart = 0;
	all->mlx->drawEnd = all->mlx->lineHeight / 2 + ((all->size->win_y / 2) + all->size->updown);
	if(all->mlx->drawEnd >= all->size->win_y)
		all->mlx->drawEnd = all->size->win_y - 1;
	if(all->size->side == 0 && map[(int)all->size->mapX][(int)all->size->mapY] == '1')
	{
		all->size->wallX = all->size->posY + all->size->perpWallDist * all->size->rayDirY;
		*ii = 1;
	}
	else
	{
		all->size->wallX = all->size->posX + all->size->perpWallDist * all->size->rayDirX;
		*ii = 2;
	}
}

void	initImgs(t_all *all)
{
	int w = 0;
	int h = 0;
	int b = 0;
	int xx = 0;

	all->mlx->tex = mlx_xpm_file_to_image(all->mlx->mlx, "Imgs/new2.xpm", &w, &h);
	all->mlx->text = (int *)mlx_get_data_addr(all->mlx->tex, &b, &h, &w);
	all->mlx->tex2 = mlx_xpm_file_to_image(all->mlx->mlx, "Imgs/new1.xpm", &w, &h);
	all->mlx->text2 = (int *)mlx_get_data_addr(all->mlx->tex2, &b, &h, &w);
	all->mlx->buffer = malloc(sizeof(int *) * all->size->win_y);
	while (xx < all->size->win_y)
	{
		all->mlx->buffer[xx] = malloc(sizeof(int) * all->size->win_x);
		xx++;
	}
}

int print_plz(t_all *all, char **map)
{
	int ii = 0;
	int x = 0;
	int y = 0;

	while (x < all->size->win_x)
	{
		initDrawing(all, x);
		initDir(all);
		getWallHit(all, map);
		getDrawPos(all, map, &ii);
		getAndFillWalls(all, y, x, ii);
		y = 0;
		fill_the_void(all, y, x);
		x++;
	}


	printf("%f      %f\n", all->size->planeX, all->size->planeY);
	printf("%f      %f\n", all->size->dirX, all->size->dirY);
	printf("________________________________________\n");


	drawall(all, all->mlx->buffer);
	all->size->moveSpeed = 0.1;
	all->size->rotSpeed = 0.055;
	return (0);
}