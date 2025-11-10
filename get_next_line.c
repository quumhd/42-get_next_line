/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:34:04 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/10 17:01:21 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*result;
	static char	buffer[BUFFER_SIZE + 1];

	result = NULL;
	result = ft_fill_buffer(result, buffer, fd);
	if (!result)
		return (NULL);
	return (result);
}
int	main(void)
{
	int		fd;
	int		i;
	char	*s;

	fd = open("read_error.txt", O_RDONLY);
	char *d = get_next_line(fd);
	printf("%s", d);
	free (d);
	close(fd);

	fd = open("read_error.txt", O_RDONLY);
	i = 0;

	while (s)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		i++;
	}
	close(fd);

	// char s1[] = "hallotest123456789";
	// ft_strlcpy(s1, &s1[5], ft_strlen(s1) - 4);
	// printf("%s", s1);
}
