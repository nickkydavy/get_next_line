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

char	*set_all_str(int fd, char *buffer)
{
	char	*str;
	int		i;

	str = (char *)malloc(1 * sizeof (char));
	while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = 0;
		if (!(str = ft_strcat(str, buffer)))
			return (0);
	}
	return (str);
}

char	*set_line(char *str, char *pstr)
{
	// char	*temp;
	// char	*substr;
	// size_t	i;
	
	// temp = (char *)malloc(1 * sizeof (char));
	// substr = (char *)malloc(2 * sizeof (char));
	// if (!temp)
	// 	return (0);
	// i = 0;
	// while (*str)
	// {
	// 	*substr = *str;
	// 	*(substr + 1) = 0;
	// 	if (!(temp = ft_strcat(temp, substr)))
	// 		return (0);
	// 	pstr = str;
	// 	str++;
	// 	if (*str == '\n')
	// 	{
	// 		*substr = '\n';
	// 		*(substr + 1) = 0;
	// 		if (!(temp = ft_strcat(temp, substr)))
	// 			return (0);
	// 		break ;
	// 	}
	// }
	// free(substr);
	char	*temp;
	size_t	len;
	size_t	i;

	if (!pstr)
		return (0);
	len = ft_strlen(str) - ft_strlen(pstr);
	temp = (char *)malloc((len + 1) * sizeof (char));
	if (!temp)
		return (0);
	i = 0;
	while (*str && str != pstr)
	{
		*(temp + i) = *str;
		str++;
		i++;
	}
	*(temp + i) = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*all_str_fd;
	static char	*next_line;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	size_t		i;

	if (!fd || !(BUFFER_SIZE > 0))
		return (0);
	if (!all_str_fd)
	{
		all_str_fd = set_all_str(fd, buffer);
		next_line = all_str_fd;
	}
	next_line = ft_strchr(next_line, '\n') + 1;
	temp = set_line(all_str_fd, next_line);
	all_str_fd = next_line;
	printf("%s", all_str_fd);
	return (temp);
}