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
	int		win_x;
	int		win_y;
	double	Pl_x;
	double	Pl_y;
	double	mid_x;
	double	mid_y;
	double	ratio;
	double	cam_x;
	double	cam_y;
	double	ray_x;
	double	ray_y;
	double	ray_x2;
	double	ray_y2;
}		t_size;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}		t_mlx;

typedef struct s_all
{
	t_size	*size;
	t_mlx	*mlx;
}			t_all;

/*--------- Functions ---------*/
void	mlx_struct_init(t_mlx *mlx, t_size *size, t_all *all);
void	mlx_main_loop(t_all *all, char *map[10]);

#endif
