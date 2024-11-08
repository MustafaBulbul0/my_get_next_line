#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
{
	int				i;
	unsigned char	new_ch;

	i = 0;
	new_ch = (unsigned char)ch;
	while (1)
	{
		if (str[i] == new_ch)
			return ((char *)&str[i]);
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	if (s1)
		len_s1 = ft_strlen(s1);
	else
		len_s1 = 0;
	if (s2)
		len_s2 = ft_strlen(s2);
	else
		len_s2 = 0;
	ptr = (char *)malloc(len_s1 + len_s2 + 1);
	if (!ptr)
		return (NULL);
	if (s1)
		ft_strlcpy(ptr, s1, len_s1 + 1);
	if (s2)
		ft_strlcat(ptr, s2, len_s1 + len_s2 + 1);
	return (ptr);
}

static char	*update_buffer(int fd, char *buffer)
{
	char	temp[2];
	int		bytes_read;
	char	*newline_ptr;

	while ((bytes_read = read(fd, temp, 1)) > 0)
	{
		temp[bytes_read] = '\0';
		char	*new_buffer;
	
		new_buffer = ft_strjoin(buffer, temp);
		if (buffer)
			free(buffer);
		buffer = new_buffer;
		if (newline_ptr = ft_strchr(buffer, '\n'))
			return (buffer);
	}
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer = NULL;
	char *line;
	char *newline_ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = update_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	if ((newline_ptr = ft_strchr(buffer, '\n')))
	{
		line = ft_strdup(buffer);
		ft_memmove(buffer, newline_ptr + 1, ft_strlen(newline_ptr + 1) + 1);
	}
	else
	{
		line = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
	}
	return line;
}
