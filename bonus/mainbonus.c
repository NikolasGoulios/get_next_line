#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

int main(int argc, char **argv)
{
    int fd, ret, line_count;
    char *line = NULL;

    if (argc > 1)
    {
        // Loop through all provided files
        for (int i = 1; i < argc; i++)
        {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1)
            {
                perror("Error opening file");
                continue; // Skip to the next file
            }

            line_count = 1;
            ret = 0;

            printf("Reading from file: %s\n", argv[i]);

            // Read lines from the file
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
    }
    else
    {
        // Read from standard input if no files are provided
        line_count = 1;
        ret = 0;

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

    return 0;
}