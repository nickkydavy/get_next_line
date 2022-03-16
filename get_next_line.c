/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:09:45 by pnimwata          #+#    #+#             */
/*   Updated: 2022/03/06 21:09:45 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	int			b;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	while ((b = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[b] = '\0';
		str = ft_strnew(1);
		ft_strjoin(str, buffer);
	}
	return (str);
}