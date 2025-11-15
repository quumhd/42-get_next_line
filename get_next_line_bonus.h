/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:45:00 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/15 17:27:19 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE + 1];
}	t_buffer;

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*clear_buffer(char *buffer);
char	*ft_together(const char *ini, const char *cat, size_t catlen);
char	*ft_fill_buffer(char *result, char *buffer, int fd, int i);
char	*add_last(char *result, char *buffer, int i);

#endif
