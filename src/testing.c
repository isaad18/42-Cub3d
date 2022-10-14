#include "../Includes/Cub3d.h"


int	closew(t_all *all)
{
	mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
	exit(0);
}

void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all)
{
	all->mlx = mlx;
	size->posX = 4;
	size->posY = 9;  //x and y start position
	size->dirX = -1;
	size->dirY = 0; //initial direction vector
	size->planeX = 0;
	size->planeY = 0.66; //the 2d raycaster version of camera plane
	size->win_x = 540;
	size->win_y = 380;
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

void	prinnt_bg(t_all *all)
{
	int	mid_y;
	int	x;

	mid_y = all->size->win_y / 2;
	x = 0;
	while (x < all->size->win_x)
	{
		mid_y = all->size->win_y / 2;
		while (mid_y > 0)
		{
			mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, x, mid_y, 0x0000F0FF);
			mid_y--;
		}
		x++;
	}
	mid_y = all->size->win_y / 2;
	x = 0;
	while (x < all->size->win_x)
	{
		mid_y = all->size->win_y / 2;
		while (mid_y < all->size->win_y)
		{
			mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, x, mid_y, 0x000FFF00);
			mid_y++;
		}
		x++;
	}
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
	int	i;

	i = 0;
	while (i < start)
	{
		mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, x, i, 0x0000F0FF);
		i++;
	}
	while (start < end)
	{
		mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, x, start, color);
		start++;
	}
	i = end + 1;
	while (i < all->size->win_y)
	{
		mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, x, i, 0x000FFF00);
		i++;
	}
}

void	drawall(t_all *all, int buffer[380][540])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
	while (i < all->size->win_x)
	{
		j = 0;
		while (j < all->size->win_y)
		{
			if (buffer[j][i] != 0)
				mlx_pixel_put(all->mlx->mlx, all->mlx->mlx_win, i, j, buffer[j][i]);
			j++;
		}
		i++;
	}
}

int print_plz(t_all *all, char *map[10])
{
  double time = 0; //time of current frame
  double oldTime = 0; //time of previous frame

	time = clock();
	int	text[64 * 64];
	for (int x = 0; x < 64; x++){
		for (int y = 0; y < 64; y++){
			text[64 * y + x] = 65536 * 192 * (x % 16 && y % 16);
		}
	}
	// text = mlx_new_image(all->mlx->mlx, 64, 64);
	// int w;
	// int h;
	// text = mlx_png_file_to_image(all->mlx->mlx, "../Imgs/greystone.png", &w, &h);
	int buffer[all->size->win_y][all->size->win_x];
	for (int y = 0; y < 64; y++){
		for (int x = 0; x < 64; x++){
			buffer[y][x] = 0;
		}
	}
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

		// int texNum = map[all->size->mapX][all->size->mapY] - 1; //1 subtracted from it so that texture 0 can be used!

      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if(all->size->side == '0') wallX = all->size->posY + all->size->perpWallDist * all->size->rayDirY;
      else          wallX = all->size->posX + all->size->perpWallDist * all->size->rayDirX;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = (int)wallX * (double)64;
      texX = 64 - texX - 1;

      // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
      // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * 64 / lineHeight;
      // Starting texture coordinate
    	double texPos = (drawStart    - all->size->win_y / 2 + lineHeight / 2) * step;
		for(int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (64 - 1);
			texPos += step;
			int color = text[64 * texY + texX];
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			buffer[y][x] = color;
			}
			for(int y = 0; y < drawStart; y++)
			{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			// if(all->size->side == 1) color = (color >> 1) & 8355711;
			buffer[y][x] = 0x87CEEB;
			}
			for(int y = drawEnd; y < all->size->win_y; y++)
			{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			// if(all->size->side == 1) color = (color >> 1) & 8355711;
			buffer[y][x] = 0x964B00;
		}
	}
	drawall(all, buffer);
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

	return 0;
}
