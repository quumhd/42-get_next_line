/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:31:07 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/01 17:15:30 by jdreissi         ###   ########.fr       */
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

size_t	ft_find_newline(char *s)
{
	size_t index;

	index = 0;
	while(s[index] != '\0')
	{
		if(s[index] == '\n')
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

char	*ft_merge(char *old, char *buffer, int *j)
{
	int		i;
	char	*merged;
	size_t	old_length;
	size_t	buffer_length;

	i = 0;
	*j = 0;
	buffer_length = 0;
	old_length = ft_strlen(old);
	while(buffer[buffer_length] != '\n' && buffer[buffer_length] != '\0')
		buffer_length++;
	merged = malloc(old_length + buffer_length + 1 * sizeof(char));
	if (!merged)
		return (NULL);
	while (old[i])
	{
		merged[i] = old[i];
		i++;
	}
	while (buffer[*j] != '\n' && buffer[*j - 1] != '\0')
	{
		merged[i] = buffer[*j];
		i++;
		*j = *j + 1;
	}
	merged[old_length + buffer_length - 1] = 0;
	return (merged);
}
