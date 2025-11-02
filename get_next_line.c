/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:34:04 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/02 16:25:02 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 111
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
	result = get_line(buffer);
	return (result);
}

int	main(void)
{
	int fd = open("text", O_RDONLY);
	int i = 0;
	char *s;
	while(i < 15)
	{
		s = get_next_line(fd);
		printf("%s\n", s);
		i++;
	}
	// s = get_next_line(fd);
	// printf("%s", s);
	close(fd);
}
