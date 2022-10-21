#ifndef CUB3D_H

# define CUB3D_H

/*---------  Macros ---------*/
# define WIN_X 1500
# define WIN_Y 2000

/*--------  Libraries --------*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <termios.h>
# include <math.h>
# include <time.h>
# include "../mlx/mlx.h"

/*---------  Colors ---------*/
# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define C "\033[0;36m"
# define P "\033[0;35m"
# define RESET "\033[0m"

/*--------- Structs ---------*/
typedef struct s_size
{
	int	where;
	double moveSpeed;
	double rotSpeed;
	double planeX;
	double planeY;
	double dirX;
	double dirY;
	double posX;
	double posY;
	int win_x;
	int win_y;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int	updown;
	int color;
	double texPos;
	double step;
	double wallX;
}		t_size;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int drawEnd;
	int drawStart;
	int lineHeight;
	int **buffer;
	int texX;
	int texY;
	int	*text;
	void	*tex;
	int	*text2;
	void	*tex2;
	long int	Ccolor;
	long int	Fcolor;
}		t_mlx;

typedef struct s_all
{
	t_size	*size;
	t_mlx	*mlx;
	char **map;
}			t_all;

/*--------- Functions ---------*/
void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all);
void	mlx_main_loop(t_all *all, char *map[10]);
int		print_plz(t_all *all, char *map[10]);
int print_plz(t_all *all, char *map[10]);
void	initImgs(t_all *all);

#endif
