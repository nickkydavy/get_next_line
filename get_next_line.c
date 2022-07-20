/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:09:45 by pnimwata          #+#    #+#             */
/*   Updated: 2022/07/20 15:18:28 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_buffer(char *base, char *src)
{
	char	*join;

	join = ft_strjoin(base, src);
	free(base);
	return (join);
}

char	*set_read_file(int fd, char *buffer)
{
	int	nbyte;
	char	*sub_buffer;
	
	if (!buffer)
		buffer = ft_calloc(1, 1);
	sub_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!sub_buffer)
		return (0);
	nbyte = 1;
	int	i = 0;
	while (nbyte > 0 && !ft_strchr(buffer, '\n'))
	{
		nbyte = read(fd,sub_buffer, BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(sub_buffer);
			return (0);
		}
		sub_buffer[nbyte] = '\0';
		buffer = join_buffer(buffer, sub_buffer);
		i++;
	}
	free(sub_buffer);
	return (buffer);
}

char	*set_output(char *buffer)
{
	int	count;
	int	i;
	char	*line;
	
	if (!buffer)
		return (0);
	i = 0;
	count = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	line = ft_calloc(count + 2, sizeof(char));
	while (i < count)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*set_next_line(char *buffer)
{
	int	count;
	int	i;
	char	*next_line;
	size_t	len_next;

	count = 0;
	if (!buffer[count])
		return (0);
	while (buffer[count] && buffer[count] != '\n')
		count++;
	len_next = ft_strlen(buffer) - count;
	next_line = ft_calloc(len_next + 1, sizeof(char));
	i = 0;
	while (buffer[count])
		next_line[i++] = buffer[++count];
	free(buffer);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*read_file;
	char		*text_output;

	if (fd < 0 || !(BUFFER_SIZE > 0) || read(fd, 0, 0) < 0)
		return (0);
	read_file = set_read_file(fd, read_file);
	if (!read_file || *read_file == 0)
		return (0);
	text_output = set_output(read_file);
	read_file = set_next_line(read_file);
	return (text_output);
}
