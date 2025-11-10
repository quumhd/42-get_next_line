/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:31:07 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/10 17:03:39 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
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

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*duplicated;

	length = ft_strlen(s) + 1;
	duplicated = (char *)malloc((length) * sizeof(char));
	if (!duplicated)
		return ((void *)0);
	ft_strlcpy(duplicated, s, length);
	return (duplicated);
}

char	*ft_together(const char *ini, const char *cat, size_t catlen)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new;

	i = 0;
	j = 0;
	len = ft_strlen(ini) + catlen;
	new = malloc(len + 1 * sizeof(char));
	if (!new)
		return (NULL);
	while (ini[i])
	{
		new[i] = ini[i];
		i++;
	}
	while (cat[j] && j < catlen)
	{
		new[i] = cat[j];
		i++;
		j++;
	}
	free((void *)ini);
	new[len] = '\0';
	return (new);
}

char	*ft_fill_buffer(char *result, char *buffer, int fd)
{
	int	i;
	int	check;

	i = 0;
	if (buffer[0] == '\0')
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1 || check == 0)
			return (NULL);
	}
	while (buffer[i] != '\n')
	{
		if (buffer[i] == '\0')
		{
			if (!result)
				result = ft_strdup(buffer);
			else
				result = ft_together(result, buffer, i);
			if (!result)
				return (NULL);
			check = read(fd, buffer, BUFFER_SIZE);
			if (check == 0)
			{
				i = 0;
				while (i < BUFFER_SIZE)
				{
					buffer[i] = '\0';
					i++;
				}
				return (result);
			}
			while (check < BUFFER_SIZE)
			{
				buffer[check] = '\0';
				check++;
			}
			i = -1;
		}
		i++;
	}
	if (!result)
	{
		result = malloc(i + 1 + 1 * sizeof(char));
		if (!result)
			return (NULL);
		ft_strlcpy(result, buffer, i + 1 + 1);
	}
	else
	{
		result = ft_together(result, buffer, i + 1);
		if (!result)
			return (NULL);
	}
	ft_strlcpy(buffer, &buffer[i + 1], BUFFER_SIZE - i);
	i = BUFFER_SIZE - i;
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
	return (result);
}
