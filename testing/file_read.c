# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int main(void)
{
    int fd;

    fd = open("lego", O_RDONLY);
    file_reader(fd);
}