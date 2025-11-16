/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:31:07 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/16 14:10:02 by jdreissi         ###   ########.fr       */
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
	ft_strlcpy (duplicated, s, length);
	return (duplicated);
}

char	*clear_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		buffer[i] = '\0';
		i++;
	}
	return (NULL);
}

char	*join_free(const char *ini, const char *cat, size_t catlen)
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
		return (free((void *)ini), NULL);
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
