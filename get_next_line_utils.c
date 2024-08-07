/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:14:21 by ngoulios          #+#    #+#             */
/*   Updated: 2024/08/07 13:25:15 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			*sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i])
		newstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		newstr[j++] = s2[i++];
	newstr[j] = 0;
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	lc ;

	lc = (unsigned char)c;
	while (*s)
	{
		if (*s == lc)
			return ((char *) s);
		s++;
	}
	if (lc == '\0')
		return ((char *) s);
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pt;

	pt = (unsigned char *) b;
	while (len > 0)
	{
		*(pt++) = (unsigned char) c;
		len--;
	}
	return (b);
}
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;
	size_t			total;

	i = 0;
	total = count * size;
	if (total > 0 && size > 0 && total >= (18446744073709551615UL) / size)
		return (NULL);
	tmp = malloc(total);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, total);
	return (tmp);
}
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
