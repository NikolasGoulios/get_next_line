/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:19:05 by ngoulios          #+#    #+#             */
/*   Updated: 2024/05/22 14:15:12 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	static char *left_c;
	char *line;
	char buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (line);
	}
	if (!buffer)
		return(NULL);
	line = fill_line_buf(fd, left_c, buffer);
	free(buffer);
	buffer = 0;
	if (!line)
		return(NULL);
	left_c = set_line(line);
	return (line);
}

	// read the file 
	// return the next line
	
	 // Read tests (learn more info about read function to create more accurate tests)
	 // int buf = 0; is the buffer that will store things from read but..
	 // static int stash = 0; it will store the whole amount of the buff 
	 // buf again 0 to start string other charaters

	 // stash will be freed but only the 
	 