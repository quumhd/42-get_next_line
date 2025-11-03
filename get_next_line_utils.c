/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:31:07 by jdreissi          #+#    #+#             */
/*   Updated: 2025/11/03 19:47:27 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	startdest;

	i = ft_strlen(dest);
	startdest = i;
	j = 0;
	if (i >= size)
		return (size + ft_strlen(src));
	while (i < size - 1 && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (ft_strlen(src) + startdest);
}

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*duplicated;

	length = ft_strlen(s) + 1;
	duplicated = (char *)malloc((length) * sizeof(char));
	if (!duplicated)
		return ((void *)0);
	ft_strlcpy(duplicated, s, length);
	return (duplicated);
}
