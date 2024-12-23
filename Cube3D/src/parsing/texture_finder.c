#include "../cub3d.h"

static void	find_noth(char *map, t_data **data)
{
    if (ft_strlen(map) < 3)
    {
        perror("Failed to add north texture\n");
        exit(1);
    }
    if ((*data)->no_flag == 1)
    {
        perror("Several North textures added, add just one\n");
        exit(1);
    }
    (*data)->no_flag = 1;
    (*data)->no_texture = ft_substr(map, 0, ft_strlen(map));
}

static void	find_south(char *map, t_data **data)
{
    if (ft_strlen(map) < 3)
    {
        perror("Failed to add south texture\n");
        exit(1);
    }
    if ((*data)->so_flag == 1)
    {
        perror("Several South textures added, add just one\n");
        exit(1);
    }
    (*data)->so_flag = 1;
    (*data)->so_texture = ft_substr(map, 0, ft_strlen(map));
}

static void	find_east(char *map, t_data **data)
{
    if (ft_strlen(map) < 3)
    {
        perror("Failed to add east texture\n");
        exit(1);
    }
    if ((*data)->ea_flag == 1)
    {
        perror("Several East textures added, add just one\n");
        exit(1);
    }
    (*data)->ea_flag = 1;
    (*data)->ea_texture = ft_substr(map, 0, ft_strlen(map));
}

static void	find_west(char *map, t_data **data)
{
    if (ft_strlen(map) < 3)
    {
        perror("Failed to add west texture\n");
        exit(1);
    }
    if ((*data)->we_flag == 1)
    {
        perror("Several West textures added, add just one\n");
        exit(1);
    }
    (*data)->we_flag = 1;
    (*data)->we_texture = ft_substr(map, 0, ft_strlen(map));
}

void	find_textures(char **map, t_data **data)
{
	int i;

	i = -1;
	while (map[++i])
	{
        printf("the string of map is %s\n", map[i]);
		if (mod_strchr(map[i], "NO"))
			find_noth(map[i], data);
		else if (mod_strchr(map[i], "SO"))
			find_south(map[i], data);
		else if (mod_strchr(map[i], "WE"))
			find_west(map[i], data);
		else if (mod_strchr(map[i], "EA"))
			find_east(map[i], data);
	}
}
