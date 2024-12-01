/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:00:14 by mubulbul          #+#    #+#             */
/*   Updated: 2024/12/01 11:12:55 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
{
	unsigned char	new_ch;

	if (!str)
		return (NULL);
	new_ch = (unsigned char)ch;
	while (*str)
	{
		if (*str == new_ch)
			return ((char *)str);
		str++;
	}
	if (new_ch == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	if (!s2)
		len_s2 = 0;
	else
		len_s2 = ft_strlen(s2);
	ptr = (char *)malloc(len_s1 + len_s2 + 1);
	if (!ptr)
		return (NULL);
	if (s1)
		ft_strlcpy(ptr, s1, len_s1 + 1);
	if (s2)
		ft_strlcat(ptr, s2, len_s1 + len_s2 + 1);
	return (ptr);
}

static char	*extract_line(char **last_address)
{
	char	*line;
	char	*temp;
	size_t	len;

	if (!*last_address || !**last_address)
	{
		free(*last_address);
		*last_address = NULL;
		return (NULL);
	}
	len = 0;
	while ((*last_address)[len] && (*last_address)[len] != '\n')
		len++;
	if ((*last_address)[len] == '\n')
		len++;
	line = ft_strndup(*last_address, len);
	temp = ft_strdup(*last_address + len);
	free(*last_address);
	*last_address = temp;
	return (line);
}

static char	*read_and_store(int fd, char *last_address)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	if (!last_address)
		last_address = ft_strdup("");
	while (!ft_strchr(last_address, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(last_address, buffer);
		free(last_address);
		last_address = temp;
	}
	free(buffer);
	return (last_address);
}

char	*get_next_line(int fd)
{
	static char	*last_address = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	last_address = read_and_store(fd, last_address);
	if (!last_address)
		return (NULL);
	line = extract_line(&last_address);
	return (line);
}
