/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:31:07 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/02 16:27:23 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

size_t	find_newline(char *s)
{
	size_t index;

	index = 0;
	while(s[index] != '\0')
	{
		if(s[index] == '\n')
			return (index);
		index++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (size == 0)
		return (ft_strlen(src));
	while (++i < size - 1 && src[i])
		dest[i] = ((char *)src)[i];
	dest[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strndup(const char *s, int length)
{
	char	*duplicated;

	duplicated = malloc(length * sizeof(char));
	if (!duplicated)
		return (NULL);
	ft_strlcpy(duplicated, s, length);
	return (duplicated);
}

char	*get_line(char *buffer)
{
	int		index;
	char	*line;

	index = find_newline(buffer);
	if(index != 0)
		return (ft_strndup(buffer, index + 2));
	while(find_newline == 0)
	{
		line = malloc(ft_strlen(buffer) * sizeof(char));
		
	}
	return (NULL);
}
