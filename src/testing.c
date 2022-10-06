#include "../Includes/Cub3d.h"

int	closew(t_all *all)
{
	mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
	exit(0);
}

// void	print_pixels(int color, t_all *all, int x, int y)
// {
// 	int i = y;
// 	int j = x;

// 	while (i < y + 50)
// 	{
// 		j = x;
// 		while (j < x + 50)
// 		{
// 			mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	keys(int keycode, t_all *all)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
// 		exit(0);
// 	}
// 	if (keycode == 0)
// 	{
// 		print_pixels(0x000000FF, all, all->size->Pl_x, all->size->Pl_y);
// 		all->size->Pl_x--;
// 		all->size->Pl_x--;
// 		all->size->Pl_x--;
// 		print_pixels(0x00F0FF0F, all, all->size->Pl_x, all->size->Pl_y);
// 		print_pixels(0x00F0FF0F, all, all->size->Pl_x, all->size->Pl_y);
// 	}
// 	if (keycode == 13)
// 	{
// 		print_pixels(0x000000FF, all, all->size->Pl_x, all->size->Pl_y);
// 		all->size->Pl_y--;
// 		all->size->Pl_y--;
// 		all->size->Pl_y--;
// 		print_pixels(0x00F0FF0F, all, all->size->Pl_x, all->size->Pl_y);
// 	}
// 	if (keycode == 1)
// 	{
// 		print_pixels(0x000000FF, all, all->size->Pl_x, all->size->Pl_y);
// 		all->size->Pl_y++;
// 		all->size->Pl_y++;
// 		all->size->Pl_y++;
// 		print_pixels(0x00F0FF0F, all, all->size->Pl_x, all->size->Pl_y);
// 	}
// 	if (keycode == 2)
// 	{
// 		print_pixels(0x000000FF, all, all->size->Pl_x, all->size->Pl_y);
// 		all->size->Pl_x++;
// 		all->size->Pl_x++;
// 		all->size->Pl_x++;
// 		print_pixels(0x00F0FF0F, all, all->size->Pl_x, all->size->Pl_y);
// 	}
// 	return (3);
// }

// void	print_map(t_all *all, char *map[10])
// {
// 	int i = 0;
// 	int j = 0;
// 	int x = 0;
// 	int y = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		x = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == '1')
// 				print_pixels(0x00FF0F0F, all, x, y);
// 			else if (map[i][j] == '0')
// 				print_pixels(0x000000FF, all, x, y);
// 			else if (map[i][j] == 'P')
// 			{
// 				print_pixels(0x00F0FF0F, all, x, y);
// 			}
// 			j++;
// 			x += 51;
// 		}
// 		y += 51;
// 		i++;
// 	}
// }

// void	print_ray_pixels(t_all *all, double counter, int new_mid)
// {
// 	double i = all->size->mid_y;
// 	double pixels = (10000.00000 * (10.0000 / (counter * 277.0000)));

// 	printf("%f\n", pixels);
// 	while (i > all->size->mid_y - pixels)
// 	{
// 		mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, new_mid, i, 0x143A6F97);
// 		i -= 0.5;
// 	}
// 	i = all->size->mid_y;
// 	while (i < all->size->mid_y + pixels)
// 	{
// 		mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, new_mid, i, 0x143A6F97);
// 		i += 0.5;
// 	}
// }

void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all)
{
	all->mlx = mlx;
	size->posX = 4;
	size->posY = 9;  //x and y start position
	size->dirX = -1;
	size->dirY = 0; //initial direction vector
	size->planeX = 0;
	size->planeY = 0.66; //the 2d raycaster version of camera plane
	size->win_x = 640;
	size->win_y = 480;
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
	size->lineHeight = 0;
	size->drawStart = 0;
	size->drawEnd = 0;
	all->size = size;
}

// double	get_dis(t_all *all, double x, double y)
// {
// 	double	dis;

// 	dis = sqrt((((double)x - all->size->Pl_x) * ((double)x - all->size->Pl_x)) + (((double)y - all->size->Pl_y) * ((double)y - all->size->Pl_y)));
// 	return (dis);
// }

// void	check_ray(t_all *all, char *map[10], int new_mid)
// {
// 	double x = all->size->Pl_x;
// 	double y = all->size->Pl_y;
// 	int counter = 0;

// 	while (map[(int)y][(int)x] != '1')
// 	{
// 		x += (all->size->temp_x / 10.000);
// 		y += (all->size->temp_y / 10.000);
// 		counter++;
// 	}
// 	print_ray_pixels(all, get_dis(all, (double)x, (int)y), new_mid);
// }

// void	print_3d(t_all *all, char *map[10])
// {
// 	while (all->size->temp_x < 0.6666)
// 	{
// 		check_ray(all, map, all->size->mid_x);
// 		all->size->temp_x += all->size->ray_x;
// 		all->size->temp_y += all->size->ray_y;
// 		all->size->mid_x += 0.5;
// 	}
// 	all->size->temp_x = all->size->cam_x;
// 	all->size->temp_y = all->size->cam_y;
// 	all->size->mid_x = all->size->win_x / 2;
// 	all->size->ray_x *= -1;
// 	while (all->size->temp_x > -0.6666)
// 	{
// 		all->size->temp_x += all->size->ray_x;
// 		all->size->temp_y += all->size->ray_y;
// 		all->size->mid_x -= 0.5;
// 		check_ray(all, map, all->size->mid_x);
// 	}
// }

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
	//move backwards if no wall behind you
	if(keycode == 1)
	{
		if(all->map[(int)(all->size->posX - all->size->dirX * all->size->moveSpeed)][(int)(all->size->posY)] != '1') all->size->posX -= all->size->dirX * all->size->moveSpeed;
		if(all->map[(int)(all->size->posX)][(int)(all->size->posY - all->size->dirY * all->size->moveSpeed)] != '1') all->size->posY -= all->size->dirY * all->size->moveSpeed;
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	//rotate to the right
	if(keycode == 2)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = all->size->dirX;
		all->size->dirX = all->size->dirX * cos(-all->size->rotSpeed) - all->size->dirY * sin(-all->size->rotSpeed);
		all->size->dirY = oldDirX * sin(-all->size->rotSpeed) + all->size->dirY * cos(-all->size->rotSpeed);
		double oldPlaneX = all->size->planeX;
		all->size->planeX = all->size->planeX * cos(-all->size->rotSpeed) - all->size->planeY * sin(-all->size->rotSpeed);
		all->size->planeY = oldPlaneX * sin(-all->size->rotSpeed) + all->size->planeY * cos(-all->size->rotSpeed);
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		print_plz(all, all->map);
	}
	//rotate to the left
	if(keycode == 0)
	{
		//both camera direction and camera plane must be rotated
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

void	mlx_main_loop(t_all *all, char *map[10])
{
	(void)map;
	all->mlx->mlx = mlx_init();
	all->mlx->mlx_win = mlx_new_window(all->mlx->mlx, all->size->win_x, all->size->win_y, "Cub3d");
	print_plz(all, map);
	mlx_hook(all->mlx->mlx_win, 2, 1L<<0, key, all);
	mlx_hook(all->mlx->mlx_win, 17, 1L<<5, closew, all);
	mlx_loop(all->mlx->mlx);
}

void	verline(t_all *all, double x, double start, double end, long long int color)
{
	printf("%f     %f\n", start, end);
	while (start < end)
	{
		mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, x, start, color);
		start++;
	}
}

int print_plz(t_all *all, char *map[10])
{
  double time = 0; //time of current frame
  double oldTime = 0; //time of previous frame

	time = clock();
	for (int x = 0; x < all->size->win_x/* W here */; x++)
	{
	  //calculate ray position and direction
	  all->size->cameraX = 2 * x / (double)all->size->win_x/* W here */ - 1; //x-coordinate in camera space
	  all->size->rayDirX = all->size->dirX + all->size->planeX * all->size->cameraX;
	  all->size->rayDirY = all->size->dirY + all->size->planeY * all->size->cameraX;
	  //which box of the map we're in
	  all->size->mapX = (int)all->size->posX;
	  all->size->mapY = (int)all->size->posY;

	  //length of ray from current position to next x or y-side
		// all->size->sideDistX;
		// all->size->sideDistY;

	  //length of ray from one x or y-side to next x or y-side
	  //these are derived as:
	  //deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
	  //deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
	  //which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
	  //where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
	  //unlike (dirX, dirY) is not 1, however this does not matter, only the
	  //ratio between deltaDistX and deltaDistY matters, due to the way the DDA
	  //stepping further below works. So the values can be computed as below.
	  // Division through zero is prevented, even though technically that's not
	  // needed in C++ with IEEE 754 floating point values.
	  all->size->deltaDistX = (all->size->rayDirX == 0) ? 1e30 : fabs(1 / all->size->rayDirX);
	  all->size->deltaDistY = (all->size->rayDirY == 0) ? 1e30 : fabs(1 / all->size->rayDirY);

	  //what direction to step in x or y-direction (either +1 or -1)
	//   all->size->stepX;
	//   all->size->stepY;

	  all->size->hit = 0; //was there a wall hit?
	//   all->size->side; //was a NS or a EW wall hit?
	  //calculate step and initial sideDist
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
	  //perform DDA
	  while(all->size->hit == 0)
	  {
		//jump to next map square, either in x-direction, or in y-direction
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
		//Check if ray has hit a wall
		if(map[all->size->mapX][all->size->mapY] != '0' && map[all->size->mapX][all->size->mapY] != 'P') all->size->hit = 1;
	  }
	  //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
	  //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
	  //This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
	  //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
	  //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
	  //steps, but we subtract deltaDist once because one step more into the wall was taken above.
	  if(all->size->side == 0) all->size->perpWallDist = (all->size->sideDistX - all->size->deltaDistX);
	  else          all->size->perpWallDist = (all->size->sideDistY - all->size->deltaDistY);

	  //Calculate height of line to draw on screen
	  int lineHeight = (int)(all->size->win_y/* H here */ / all->size->perpWallDist);

	  //calculate lowest and highest pixel to fill in current stripe
	  int drawStart = -lineHeight / 2 + all->size->win_y/* H here */ / 2;
	  if(drawStart < 0) drawStart = 0;
	  int drawEnd = lineHeight / 2 + all->size->win_y/* H here */ / 2;
	  if(drawEnd >= all->size->win_y/* H here */) drawEnd = all->size->win_y/* H here */ - 1;

	  //choose wall color
	  long long int color;
		if (map[all->size->mapX][all->size->mapY] == '1')
			color = 0x143A6F97;
		else
			color = 0;

	  //give x and y sides different brightness
	//   if(side == 1) {color = color / 2;}

	  //draw the pixels of the stripe as a vertical line
		verline(all, x, drawStart, drawEnd, color); //draw here
	}
	//timing for input and FPS counter
	oldTime = time;
	time = clock();
	double frameTime = (time - oldTime) / 5009000.0; //frameTime is the time this frame has taken, in seconds
	// print(1.0 / frameTime); //FPS counter
	// redraw();
	// cls();

	//speed modifiers
	all->size->moveSpeed = frameTime * 5.0; //the constant value is in squares/second
	all->size->rotSpeed = frameTime * 3.0; //the constant value is in radians/second


	//moving part
	//move forward if no wall in front of you
	// readKeys();
	// if(keyDown(SDLK_UP))
	// {
	//   if(map[(int)(posX + dirX * moveSpeed)][(int)(posY)] == false) posX += dirX * moveSpeed;
	//   if(map[(int)(posX)][(int)(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
	// }
	// //move backwards if no wall behind you
	// if(keyDown(SDLK_DOWN))
	// {
	//   if(map[(int)(posX - dirX * moveSpeed)][(int)(posY)] == false) posX -= dirX * moveSpeed;
	//   if(map[(int)(posX)][(int)(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
	// }
	// //rotate to the right
	// if(keyDown(SDLK_RIGHT))
	// {
	//   //both camera direction and camera plane must be rotated
	//   double oldDirX = dirX;
	//   dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
	//   dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
	//   double oldPlaneX = planeX;
	//   planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	//   planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	// }
	// //rotate to the left
	// if(keyDown(SDLK_LEFT))
	// {
	//   //both camera direction and camera plane must be rotated
	//   double oldDirX = dirX;
	//   dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
	//   dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
	//   double oldPlaneX = planeX;
	//   planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
	//   planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	// }

	return 0;
}
