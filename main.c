#include <fcntl.h>    // For open
#include <unistd.h>   // For close
#include <stdio.h>    // For printf, perror
#include <stdlib.h>   // For exit
#include <limits.h>
#include "get_next_line.h" 

/*int main(int argc, char **argv)
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
}*/

int main(int argc, char **argv)
{
    int fd, ret, line_count;
    char *line = NULL;

    line_count = 1;
    ret = 0;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            perror("Error opening file");
            return 1;
        }
        while ((line = get_next_line(fd)) != NULL)
        {
            ret = 1; 
            printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
            line_count++;
            free(line);
        }
        if (line == NULL && ret == -1)
        {
            printf("-----------\nAn error happened\n");
        }
        else
        {
            printf("-----------\nEOF has been reached\n");
        }
        close(fd);
    }
    else if (argc == 1)
    {
        while ((line = get_next_line(0)) != NULL)
        {
            ret = 1; 
            printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
            line_count++;
            free(line);
        }
        if (line == NULL && ret == -1)
        {
            printf("\nAn error happened\n");
        }
        else
        {
            printf("\nEOF has been reached\n");
        }
    }
    else
    {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    return 0;
}