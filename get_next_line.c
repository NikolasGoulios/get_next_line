/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:43:54 by ngoulios          #+#    #+#             */
/*   Updated: 2024/07/24 13:22:27 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *backup);
static char	*extract(char *line);
static char *join_and_free(char *s1, char *s2);

char *get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	line = read_line(fd, backup);
	if (!line)
		return (NULL);

	backup = extract(line);
	return (line);
}
static char	*read_line(int fd, char *backup)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = join_and_free(backup, buffer);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
		backup = temp;
		if (ft_strchr(backup, '\n'))
			break;
	}
	free(buffer);
	if (bytes_read < 0)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	return (backup);
}
static char	*extract(char *line)
{
	int		i;
	char	*remainder;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\n')
		i++;
	if (line[i + 1] == '\0')
		return (NULL);
	remainder = ft_substr(line, i + 1, ft_strlen(line));
	if (!remainder)
		return (NULL);
	//free(line);
	return (remainder);
}
static char *join_and_free(char *s1, char *s2)
{
	char *joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}
