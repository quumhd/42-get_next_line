/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:34:04 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/09 16:35:36 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int		i;
	int		check;
	char	*temp;
	char	*result;
	char	buffer[BUFFER_SIZE + 1];

	i = 0;
	result = NULL;
	buffer[BUFFER_SIZE] = '\0';
	check = read(fd, &buffer[i], 1);
	if (check == 0 || check == -1)
		return (NULL);
	result = ft_fill_buffer(result, buffer, fd, i);
	if (!result)
		result = ft_strdup(buffer);
	else
		result = ft_together(result, buffer);
	if (!result)
		return (NULL);
	return (result);
}
	
int	main(void)
{
	int		fd;
	int		i;
	char	*s;

	fd = open("text", O_RDONLY);
	i = 0;
	while (s)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		i++;
	}
	close(fd);
}
