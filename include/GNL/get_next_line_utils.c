/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:36:30 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/15 13:48:23 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	len_str;
	char			*result;

	if (!s)
		return (NULL);
	len_str = ft_strlen((char *) s);
	if (start >= len_str)
		return (ft_calloc(1, sizeof(char)));
	if (len > len_str - start)
		len = len_str - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (count * size > i)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	caract;

	i = 0;
	caract = (char) c;
	while (s[i])
	{
		if (s[i] == caract)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == caract)
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(src);
	dup = malloc(sizeof (char) * (size + 1));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_custom(char *s1, char *s2)
{
	char	*new_str;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	copy_strings(new_str, s1, 0);
	copy_strings(new_str, s2, len1);
	new_str[len1 + len2] = '\0';
	free(s1);
	return (new_str);
}
