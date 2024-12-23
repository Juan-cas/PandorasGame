#ifndef CUB3D_H
# define CUBED3_H

# ifndef ASSETS_H
#  define ASSETS_H
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define K_A 0
# define K_S 1
# define K_D 2
# define K_W 13
# define ARROW_KEY_LEFT 123
# define ARROW_KEY_RIGHT 124
# define ARROW_KEY_UP 126
# define ARROW_KEY_DOWN 125
# define KEY_ESC 53

# define MLX_SYNC_IMAGE_WRITABLE 1
# define MLX_SYNC_WIN_FLUSH_CMD 2
# define MLX_SYNC_WIN_CMD_COMPLETED 3


# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct mlx_pointers
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[6];
	int		winysize;
	int		winxsize;
}			t_mlx_p;

typedef struct game_data
{
	char	*no_texture;
	int		no_flag;
	char	*so_texture;
	int		so_flag;
	char	*we_texture;
	int		we_flag;
	char	*ea_texture;
	int		ea_flag;
	char	**f_colors;
	int		f_flag;
	char	**c_colors;
	int		c_flag;
	char	**map;
}			t_data;

// error
void		malloc_check(void *ptr);

// parsing
void		parsing_control(char **map, t_data **data);
void		find_textures(char **map, t_data **data);
void		find_ceeling_floor(char **map, t_data **data);

// utils
int			mod_strchr(char *s1, char *s2);
int			matrix_counter(char **matrix);
char		*get_next_line(int fd);

// movements

#endif