/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:19:05 by ngoulios          #+#    #+#             */
/*   Updated: 2024/07/09 17:50:05 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buf, char *backup);
static char	*extract(char *line);

char *get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	backup;

	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, &backup);
	free(buffer);
	if (!line)
		return (NULL);
	backup = *extract(line);
	return (line);
}
static char	*read_line(int fd, char *buffer, char *backup)
{
	int		check;
	char	*temp;

	check = 1;
	while (check)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (0);
		else if (check == 0)
			break;
		buffer[check] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = (ft_strjoin(temp, buffer));
		if (!backup)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (backup);
}
static char	*extract(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		i++;
	}
	if (line[i] == 0)
		return (NULL);
	temp = ft_substr(line, i + 1, ft_strlen(line) - 1);
	if (!temp)
	{
		free (temp);
		temp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (temp);
}
