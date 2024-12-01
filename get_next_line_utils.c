/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:45:55 by mubulbul          #+#    #+#             */
/*   Updated: 2024/12/01 10:01:31 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *len)
{
	size_t	i;

	i = 0;
	if (len == NULL)
		return (0);
	while (len[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(n + 1);
	if (!ptr)
		return (NULL);
	while (i < n && str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t sizeDest)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (sizeDest == 0)
		return (src_len);
	while (src[i] && (i < sizeDest - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t sizeDest)
{
	size_t	i;
	size_t	s_dest;
	size_t	s_src;

	i = 0;
	s_dest = ft_strlen(dest);
	s_src = ft_strlen(src);
	if (sizeDest <= s_dest)
		return (sizeDest + s_src);
	if (sizeDest == 0)
		return (s_dest);
	while (src[i] && (s_dest + i) < (sizeDest - 1))
	{
		dest[s_dest + i] = src[i];
		i++;
	}
	dest[s_dest + i] = '\0';
	return (s_dest + s_src);
}
