/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:09:45 by pnimwata          #+#    #+#             */
/*   Updated: 2022/03/22 15:40:59 by pnimwata         ###   ########.fr       */
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

size_t	where_is_nl(buffer)
{
	size_t	size;
	
	size = ft_strlen(buffer) - ft_strlen(ft_strchr(buffer, '\n'));
	return (size);
}

char	*get_next_line(int fd)
{
	static size_t	count;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
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
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		count += where_is_nl(buffer);
		
		temp = ft_strjoin(temp, buffer);
		printf("%d", (int)ft_strchr(buffer, '\n'));
		if (ft_strchr(buffer, '\n'))
		{
			printf("passthis");
			break ;
		}
	}
	if (!temp[0])
		return (0);
	return (temp);
}
