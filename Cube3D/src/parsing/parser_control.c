#include "../cub3d.h"

static void	init_data_struct(t_data **data)
{
	(*data)->no_texture = NULL;
	(*data)->so_texture = NULL;
	(*data)->ea_texture = NULL;
	(*data)->we_texture = NULL;
	(*data)->c_colors = NULL;
	(*data)->f_colors = NULL;
	(*data)->map = NULL;
	(*data)->no_flag = 0;
	(*data)->so_flag = 0;
	(*data)->ea_flag = 0;
	(*data)->we_flag = 0;
	(*data)->f_flag = 0;
	(*data)->c_flag = 0;
}

void	parsing_control(char **map, t_data **data)
{
	init_data_struct(data);
	find_textures(map, data);
	find_ceeling_floor(map, data);
	find_map(map, data);
}