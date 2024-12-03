/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:26:40 by marvin            #+#    #+#             */
/*   Updated: 2024/12/02 19:26:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//todo lo que vayamos leyendo lo vamos metiendo en saved
char	*read_line(int fd, char *saved)
{
	char	*buffer;
	ssize_t	count;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	count = 1;
	while (!ft_strchr(saved, '\n') && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	free (buffer);
	return (saved);
}

//esta función extrae la primera linea desde saved y lo mete en new_saved
char	*new_line(char *saved)
{
	int			i;
	char		*line_read;

	if (!saved[0])
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	line_read = (char *)malloc((i + 2) * sizeof(char));
	if (!line_read)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line_read[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		line_read[i++] = '\n';
	line_read[i] = '\0';
	return (line_read);
}

char	*reset_saved(char *saved)
{
	int		i;
	int		j;
	char	*new_saved;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	new_saved = (char *)malloc((ft_strlen(saved) - i + 1) * sizeof(char));
	if (!new_saved)
		return (NULL);
	i++;
	j = 0;
	while (saved[i])
		new_saved[j++] = saved[i++];
	new_saved[j] = '\0';
	free(saved);
	return (new_saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_line(fd, saved);
	if (!saved)
		return (NULL);
	line = new_line(saved);
	saved = reset_saved(saved);
	return (line);
}
