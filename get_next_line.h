#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>



char	*get_next_line(int fd);

size_t	ft_strlen(const char *len);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int ch);
size_t	ft_strlcpy(char *dest, const char *src, size_t sizeDest);
size_t	ft_strlcat(char *dest, const char *src, size_t sizeDest);
char	*ft_strjoin(char const *s1, char const *s2);

#endif