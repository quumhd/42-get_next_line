/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:33:35 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/16 15:21:07 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE + 1];
}	t_buffer;

char	*get_next_line(int fd);

int		fill_empty_buffer(int fd, char *buffer);
char	*add_last(char *result, char *buffer, int i);
char	*read_until_newline(char *result, char *buffer, int fd, int i);
char	*add_last(char *result, char *buffer, int i);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*clear_buffer(char *buffer);
char	*join_free(const char *ini, const char *cat, size_t catlen);

#endif
