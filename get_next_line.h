/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:33:35 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/13 15:49:50 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*clear_buffer(char *buffer);
char	*ft_together(const char *ini, const char *cat, size_t catlen);
char	*ft_fill_buffer(char *result, char *buffer, int fd, int i);
char	*add_last(char *result, char *buffer, int i);

#endif
