#include "../cub3d.h"

static void f_c_checker(char *map)
{
    int i;

    i = -1;
    while (map[++i])
    {
        if (map[i] != ' ' && !ft_isdigit(map[i]) && map[i] != ',')
        {
            perror("Please check arguments for F or C\n");
            exit(1);
        }
    }
}

static void	add_floor_color(char *map, t_data **data)
{
	char	*tmp_str;

	tmp_str = ft_substr(map, 1, ft_strlen(map));
    f_c_checker(tmp_str);
	(*data)->f_colors = ft_split(tmp_str, ',');
	if (matrix_counter((*data)->f_colors) < 3)
	{
		perror("Please Check Floor Color Argument\n");
		exit(1);
	}
}

static void	add_ceeling_color(char *map, t_data **data)
{
	char	*tmp_str;

	tmp_str = ft_substr(map, 1, ft_strlen(map));
    f_c_checker(tmp_str);
	(*data)->c_colors = ft_split(tmp_str, ',');
	if (matrix_counter((*data)->c_colors)  < 3)
	{
		perror("Please Check Floor Color Argument\n");
		exit(1);
	}
}

void	find_ceeling_floor(char **map, t_data **data)
{
	int i;

	i = -1;
	while (map[++i])
	{
		if (map[i][0] == 'F')
			add_floor_color(map[i], data);
		if (map[i][0] == 'C')
			add_ceeling_color(map[i], data);
	}
}