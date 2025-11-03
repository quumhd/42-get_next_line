/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:34:04 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/03 19:48:32 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

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

char	*get_next_line(int fd)
{
	int		i;
	int		check;
	char	*temp;
	char	*result;
	char	buffer[BUFFER_SIZE];

	i = 0;
	buffer[BUFFER_SIZE - 1] = '\0';
	check = read(fd, &buffer[i], 1);
	if (check == 0 || check == -1)
		return (NULL);
	while (buffer[i++] != '\n')
	{
		if(!(i + 1 < BUFFER_SIZE))
		{
			temp = ft_strdup(result);
			result = malloc(ft_strlen(result) + BUFFER_SIZE * sizeof(char));
			ft_strlcat(result, buffer, sizeof(result) + BUFFER_SIZE);
			i = 0;
			printf("buffer: %s", buffer);	
			printf("[]\n");
			break;
		}
		check = read(fd, &buffer[i], 1);
		if (check == -1)
			return (NULL);
		if (check == 0)
			break ;
	}
	printf("[%d]\t", i);
	result = malloc(sizeof(result) + i + 1 * sizeof(char));
	ft_strlcat(result, buffer, sizeof(result) + BUFFER_SIZE);
	return (result);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*s;

	fd = open("text", O_RDONLY);
	i = 0;
	while (i < 8)
	{
		s = get_next_line(fd);
		printf("%s\n", s);
		i++;
	}
	// s = get_next_line(fd);
	// printf("%s", s);
	close(fd);
}
