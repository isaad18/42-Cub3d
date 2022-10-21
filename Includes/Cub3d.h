#ifndef CUB3D_H

# define CUB3D_H

/*--------  Libraries --------*/
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include "../mlx/mlx.h"
/*--------  Libraries --------*/

/*---------  Colors ---------*/
# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define C "\033[0;36m"
# define P "\033[0;35m"
# define RESET "\033[0m"
/*---------  Colors ---------*/

/*--------- Structs ---------*/
typedef struct s_size
{
	int		hit;
	int		side;
	int		mapX;
	int		mapY;
	double	dirX;
	double	dirY;
	double	posX;
	double	posY;
	double	step;
	double	wallX;
	int		where;
	int		win_x;
	int		win_y;
	int		stepX;
	int		stepY;
	int		color;
	double	planeX;
	double	planeY;
	double	texPos;
	int		updown;
	int		drawEnd;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	rotSpeed;
	double	moveSpeed;
	int		drawStart;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	int		lineHeight;
	double	deltaDistY;
	double	perpWallDist;
}			t_size;

typedef struct s_mlx
{
	void		*mlx;
	int			texX;
	int			texY;
	void		*tex;
	int			*text;
	void		*tex2;
	int			*text2;
	long int	Ccolor;
	long int	Fcolor;
	int			drawEnd;
	void		*mlx_win;
	int			**buffer;
	int			drawStart;
	int			lineHeight;
}			t_mlx;

typedef struct s_all
{
	t_size	*size;
	t_mlx	*mlx;
	char	**map;
}			t_all;
/*--------- Structs ---------*/

/*--------- Functions ---------*/
void	key0(t_all *all);
void	key1(t_all *all);
void	key2(t_all *all);
void	keyup(t_all *all);
void	key13(t_all *all);
int		closew(t_all *all);
void	key123(t_all *all);
void	key124(t_all *all);
void	initDir(t_all *all);
void	keydown(t_all *all);
void	initImgs(t_all *all);
int		key(int keycode, t_all *all);
void	initDrawing(t_all *all, int x);
int		mouse(int x, int y, t_all *all);
int		print_plz(t_all *all, char **map);
void	getWallHit(t_all *all, char **map);
void	mlx_main_loop(t_all *all, char **map);
void	getDrawPos(t_all *all, char **map, int *ii);
void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all);
/*--------- Functions ---------*/

#endif
