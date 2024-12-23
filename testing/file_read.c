# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


char *file_reader(int fd)
{
    
}

int main(void)
{
    int fd;

    fd = open("lego", O_RDONLY);
    file_reader(fd);
}