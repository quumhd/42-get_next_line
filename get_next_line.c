/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:34:04 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/13 17:21:38 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*add_last(char *result, char *buffer, int i)
{
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
		buffer[i++] = '\0';
	return (result);
}

char	*ft_fill_buffer(char *result, char *buffer, int fd, int i)
{
	int	check;

	while (buffer[++i] != '\n')
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
				clear_buffer(buffer);
				return (result);
			}
			while (check < BUFFER_SIZE)
				buffer[check++] = '\0';
			i = -1;
		}
	}
	result = add_last(result, buffer, i);
	return (result);
}

char	*get_next_line(int fd)
{
	int			i;
	int			check;
	char		*result;
	static char	buffer[BUFFER_SIZE + 1];

	i = -1;
	result = NULL;
	if (buffer[0] == '\0')
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1 || check == 0)
			return (clear_buffer(buffer));
	}
	if (read (fd, buffer, 0) == -1)
		return (clear_buffer(buffer));
	result = ft_fill_buffer(result, buffer, fd, i);
	if (!result)
	{
		free(result);
		return (free(result), NULL);
	}
	return (result);
}
// int	main(void)
// {
// 	char	*output;
// 	int		fd = open("giant_line.txt", O_RDONLY);
// 	output = get_next_line(fd);
// 	printf("1:	%s", output);
// 	free(output);
// 	close (fd);
// 	output = get_next_line(764);
// 	printf("invalid:	%s", output);
// 	free(output);
// 	fd = open("giant_line.txt", O_RDONLY);
// 	output = get_next_line(fd);
// 	printf("1:	%s", output);
// 	free(output);
// 	close(fd);
// }
