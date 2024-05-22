/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:18:52 by ngoulios          #+#    #+#             */
/*   Updated: 2024/05/22 13:37:55 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

  //ft_strchr
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
  //ft_strdup
char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
  //ft_strlen
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
  //ft_substr
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
  //ft_strjoin
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