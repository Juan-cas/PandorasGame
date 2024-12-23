#include "cub3d.h"

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
	parsing_control(map, data);
	return (0);
}