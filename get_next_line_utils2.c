/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:45:27 by mubulbul          #+#    #+#             */
/*   Updated: 2024/11/24 16:13:15 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
