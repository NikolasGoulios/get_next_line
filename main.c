#include <fcntl.h>    // For open
#include <unistd.h>   // For close
#include <stdio.h>    // For printf, perror
#include <stdlib.h>   // For exit
#include "get_next_line.h" // Include the header for get_next_line

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    if (close(fd) < 0)
    {
        perror("Error closing file");
        return (1);
    }

    return (0);
}