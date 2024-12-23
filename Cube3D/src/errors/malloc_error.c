#include "../cub3d.h"


void malloc_check(void *ptr)
{
    if (!ptr)
    {
        perror("Malloc creation has failed\n");
        exit(1);
    }
}