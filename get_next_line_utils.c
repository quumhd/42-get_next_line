/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:31:07 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/09 16:19:46 by jdreissi         ###   ########.fr       */
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

char	*ft_together(const char *ini, const char *cat)
{
	int		i;
	int		j;
	char	*new;
	size_t	len;

	i = -1;
	j = 0;
	len = ft_strlen(ini) + ft_strlen(cat);
	new = malloc(len + 1);
	if(!new)
		return (NULL);
	new[len] = '\0';
	while (ini[++i])
		new[i] = ini[i];
	while (cat[j])
		new[i++] = cat[j++];
	new[i] = '\0';
	free((void *)ini);
	return new;
}

char	*ft_fill_buffer(char *result, char *buffer, int fd, int i)
{
	int	check;

	while (buffer[i++] != '\n')
	{
		if (i == BUFFER_SIZE)
		{
			if (!result)
				result = ft_strdup(buffer);
			else
				result = ft_together(result, buffer);
			if (!result)
				return (NULL);
			i = -1;
			while (++i < BUFFER_SIZE)
				buffer[i] = '\0';
			i = 0;
		}
		check = read(fd, &buffer[i], 1);
		if (check == -1)
			return (NULL);
		if (check == 0)
			break ;
	}
	return (result);
}
