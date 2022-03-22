/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:09:45 by pnimwata          #+#    #+#             */
/*   Updated: 2022/03/22 16:53:57 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*blank_str(size_t num)
{
	char	*str;
	
	str = (char *)ft_calloc(num + 1, sizeof (char));
	if (!str)
		return (0);
	return (str);
}

size_t	where_is_nl(char const *buffer)
{
	size_t	size;
	
	size = ft_strlen(buffer) - ft_strlen(ft_strchr(buffer, '\n'));
	return (size);
}

char	*get_line(char *temp, char *buffer, size_t size)
{
	char	*str;
	size_t	len;
	
	len = 0;
	str = (char *)ft_calloc(size, sizeof (char));
	while (*temp)
	{
		*(str + len) = *temp;
		temp++;
		len++;
	}
	while (len < size && *buffer)
	{
		*(str + len) = *buffer;
		buffer++;
		len++;
	}
	*(str + len) = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	static size_t	count;
	char		*temp;
	static char		buffer[BUFFER_SIZE + 1];
	size_t		size;
	size_t		i;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	i = 0;
	count = 0;
	while (i < count)
	{
		read(fd, buffer, BUFFER_SIZE);
		i++;
	}
	temp = blank_str(1);
	size = 0;
	printf("passthis");
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		size = where_is_nl(buffer);
		// temp = ft_strjoin(temp, buffer);
		temp = get_line(temp, buffer, size);
		count += size;
		// printf("%d", (int)ft_strchr(buffer, '\n'));
		if (size != ft_strlen(buffer))
		{
			printf("passthis");
			break ;
		}
	}
	if (!temp[0])
		return (0);
	return (temp);
}
