/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:34:04 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/01 17:14:00 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

char	*get_next_line(int fd)
{
	int			copied;
	int			length;
	char		*result;
	static char	buffer[BUFFER_SIZE + 1];

	length = 0;
	if (buffer[0] == '\0')
	{
		copied = read(fd, buffer, BUFFER_SIZE);
		if (copied == 0 || copied == -1)
			return (NULL);
	}
	while (buffer[length] != '\n' && buffer[length] != '\0')
		length++;
	if (buffer[length] == '\n')
	{
		result = malloc(length + 2 * sizeof(char));
		if (!result)
			return (NULL);
		ft_strlcpy(result, buffer, length + 2);
	}
	else
	{
		result = malloc(length + 1 * sizeof(char));
		if (!result)
			return (NULL);
		ft_strlcpy(result, buffer, length + 1);
	}
	while(ft_find_newline(result) == 0)
	{
		ft_strlcpy(buffer, &buffer[length + 1], BUFFER_SIZE + 1 - length);
		read(fd, &buffer[length], length);
		result = ft_merge(result, buffer, &length);
	}
	return (result);
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int i = 0;
	char *s;
	while(i < 15)
	{
		s = get_next_line(fd);
		printf("%s", s);
		i++;
	}
	// s = get_next_line(fd);
	// printf("%s", s);
	close(fd);
}