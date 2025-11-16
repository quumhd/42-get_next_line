/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:34:04 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/16 15:16:13 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	fill_empty_buffer(int fd, char *buffer)
{
	int	check;

	check = 1;
	if (buffer[0] == '\0')
	{
		check = read(fd, buffer, BUFFER_SIZE);
	}
	return (check);
}

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
		result = join_free(result, buffer, i + 1);
		if (!result)
			return (NULL);
	}
	ft_strlcpy(buffer, &buffer[i + 1], BUFFER_SIZE - i);
	i = BUFFER_SIZE - i;
	while (i <= BUFFER_SIZE)
		buffer[i++] = '\0';
	return (result);
}

char	*read_until_newline(char *result, char *buffer, int fd, int i)
{
	int	check;

	while (buffer[++i] != '\n')
	{
		if (buffer[i] == '\0')
		{
			if (!result)
				result = ft_strdup(buffer);
			else
				result = join_free(result, buffer, i);
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
	char			*result;
	static t_buffer	buffer[1024];

	result = NULL;
	if (fill_empty_buffer(fd, buffer[fd].buffer) <= 0 || read(fd, 0, 0) == -1)
		return (clear_buffer(buffer[fd].buffer));
	result = read_until_newline(result, buffer[fd].buffer, fd, -1);
	if (!result)
		return (free(result), NULL);
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
