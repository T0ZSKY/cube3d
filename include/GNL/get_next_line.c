/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tom.limon@>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:36:11 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/15 13:49:36 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = ft_substr(str, 0, i + 1);
	else
		line = ft_substr(str, 0, i);
	return (line);
}

char	*update_static_buffer(char *buffer, int start)
{
	int		len;
	char	*new_buffer;

	len = 0;
	while (buffer[start + len])
		len++;
	new_buffer = ft_substr(buffer, start, len);
	if (!new_buffer)
		return (free(buffer), NULL);
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	char		*line;
	int			byte_read;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		buffer = ft_strdup("");
	while (!ft_strchr(buffer, '\n'))
	{
		byte_read = read(fd, tmp, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(tmp), free(buffer), buffer = NULL, NULL);
		tmp[byte_read] = '\0';
		buffer = ft_strjoin_custom(buffer, tmp);
		if (byte_read == 0)
			break ;
	}
	free(tmp);
	if (!*buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = ft_line(buffer);
	buffer = update_static_buffer(buffer, ft_strlen(line));
	return (line);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	copy_strings(char *dest, const char *src, int start)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[start + i] = src[i];
		i++;
	}
}
/*
#include <fcntl.h>    // pour open
#include <stdio.h>    // pour printf

int main(void)
{
    const char *fileName = "./test.txt";
    int fd = open(fileName, O_RDONLY);
    int i = 0;

    char *line;
    while ((line = get_next_line(fd)) != NULL && i < 50000)
    {
        printf("%s\n",line);
        free(line);
        i++;
    }

    close(fd);
    return 0;
}
*/
