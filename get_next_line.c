/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:09:45 by pnimwata          #+#    #+#             */
/*   Updated: 2022/03/21 18:04:13 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	temp = ft_strnew(1);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		printf("%zu ", count);
		buffer[BUFFER_SIZE] = '\0';
		temp = ft_strjoin(temp, buffer);
		count++;
		if (buffer[0] == '\n')
			break ;
	}
	printf("%d", (int)temp[0]);
	if (!temp)
		return (0);
	//printf("%s", str);
	return (temp);
}
