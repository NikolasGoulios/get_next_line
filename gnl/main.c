/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:24:58 by ngoulios          #+#    #+#             */
/*   Updated: 2024/07/30 21:01:07 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/fcntl.h>

/*int main()
{
	char *str;
	int fd = open("tests/normal.txt", O_RDONLY);
	if (fd < 0) { 
        printf("\033[1;31mCould not open file\n"); 
        return 0377; 
    }
	while(get_next_line(fd, &str))
		free(str);
	free(str);
	fd = open("tests/long_line.txt", O_RDONLY);
	if (fd < 0) { 
        printf("\033[1;31mCould not open file\n"); 
        return 0377; 
    }
	while(get_next_line(fd, &str))
		free(str);
	free(str);
}*/
/*
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("normal.txt", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}*/


#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int fd, ret, line_count;
	char *line;

	line_count = 1;
	ret = 0;
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd)) > 0)
		{
			printf(" \n [ Return: %d ] | A line has been read #%d => %s\n", ret, line_count, line);
			line_count++;
			free(line);
		}
		printf(" \n [ Return: %d ] A line has been read #%d: %s\n", ret, line_count++, line);
		printf("\n");
		if (ret == -1)
			printf("-----------\n An error happened\n");
		else if (ret == 0)
		{
			printf("-----------\n EOF has been reached\n");
			free(line);
		}
		close(fd);
	}
	if (argc == 1)
	{
		while ((ret = get_next_line(0)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
			line_count++;
		}
		if (ret == -1)
			printf("\n An error happened\n");
		else if (ret == 0)
			printf("\n EOF has been reached\n");
		close(fd);
	}
	return (0);
}