#include "../Includes/Cub3d.h"

void	mlx_main_loop(t_all *all, char **map)
{
	all->mlx->mlx = mlx_init();
	all->mlx->mlx_win = mlx_new_window(all->mlx->mlx, all->\
	size->win_x, all->size->win_y, "Cub3d");
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
	int	*texture;

	i = 0;
	j = 0;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	all->mlx->img = mlx_new_image(all->mlx->mlx, all->size->win_x, all->size->win_y);
	texture = (int *)mlx_get_data_addr(all->mlx->img, &all->mlx->b, &all->mlx->w, &all->mlx->h);
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
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->mlx_win, all->mlx->img, 0, 0);
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
		if (all->mlx->buffer[y][x] == 0 && all->size->updown > 0 &&\
		 (y < all->mlx->drawStart || y > all->mlx->drawEnd))
			all->mlx->buffer[y][x] = all->mlx->Ccolor;
		if (all->mlx->buffer[y][x] == 0 && all->size->updown < 0 &&\
		 (y < all->mlx->drawStart || y > all->mlx->drawEnd))
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

void	clearBuffer(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->size->win_y)
	{
		j = 0;
		while (j < all->size->win_x)
		{
			all->mlx->buffer[i][j] = 0;
			j++;
		}
		i++;
	}
}

int print_plz(t_all *all, char **map)
{
	int ii = 0;
	int x = 0;
	int y = 0;

	clearBuffer(all);
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