/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:19:05 by ngoulios          #+#    #+#             */
/*   Updated: 2024/05/26 16:13:35 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*fill_line_buf(int fd, char *left_c, char *buffer);
static	char	*set_line(char *line_buffer);

char	*get_next_line(int fd)
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

static	char	*fill_line_buf(int fd, char *left_c, char *buffer)
{
	size_t b_read;
	char *tmp;

	b_read = 1;
	while (b_read >0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (b_read == 0)
			break;
		buffer[b_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (left_c);

}
static	char	*set_line(char *line_buffer)
{
	char	*left_c;
    size_t	i;
    
    i = 0;
    /* This loop let's us find the end of the line
     * either when we encounter a \n or a \0
     */
    while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
        i++;
    /* here we check if the current or next character is a \0
     * if this is the case, this means that the line is empty so
     * we return NULL, this is what the subject asks us, send NULL
     * if there is no next line
     */
    if (line_buffer[i] == 0 || line_buffer[1] == 0)
        return (NULL);
    /* here we take a substring from the end of the line to the end
     * of the whole line_buffer, that's what's left from our line
     */
    left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
    if (*left_c == 0)
    {
        free(left_c);
        left_c = NULL;
    }
    /* don't forget to set the last character to \0 to NUL-terminate
     * the line
     */    
    line_buffer[i + 1] = 0;
    return (left_c);
	
}
