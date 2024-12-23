#include "../cub3d.h"

int matrix_counter(char **matrix)
{
    int i;

    i = -1;
    while(matrix[++i]);

    return (i);
}