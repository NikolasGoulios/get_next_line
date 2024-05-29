/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:18:52 by ngoulios          #+#    #+#             */
/*   Updated: 2024/05/29 16:09:50 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!dest)
		return (NULL);
	while (!s1)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	new_len;

	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	new_len = ft_strlen(s) - start;
	if (new_len < len)
		len = new_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

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
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
		ft_memcpy (dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy (dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (srclen);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		index;
	char		*de;
	char		*sr;

	index = 0;
	de = (char *)dst;
	sr = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (index < n)
	{
		de[index] = sr[index];
		index++;
	}
	return (dst);
}