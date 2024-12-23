#include "cub3d.h"

static void matrix_printer(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		printf("%s\n", matrix[i]);
}

static void data_printer(t_data **data)
{
	printf("%s\n",(*data)->ea_texture);
	printf("%s\n",(*data)->no_texture);
	printf("%s\n",(*data)->we_texture);
	printf("%s\n",(*data)->so_texture);
	matrix_printer((*data)->f_colors);
	matrix_printer((*data)->c_colors);
}

static char	**file_opener(char *file)
{
	int		fd;
	char	*big_line;
	char	**map_matrix;

	fd = open(file, O_RDONLY);
	big_line = NULL;
	if (fd < 0)
	{
		perror("Opening fd failed\n");
		exit(1);
	}
	big_line = get_next_line(fd);
	map_matrix = ft_split(big_line, '\n');
	return (map_matrix);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	char **map;
	t_data *data;

	data = ft_calloc(1, sizeof(t_data));
	map = file_opener(argv[1]);
	parsing_control(map, &data);
	data_printer(&data);
	return (0);
}