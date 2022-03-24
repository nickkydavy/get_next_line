/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:10:46 by pnimwata          #+#    #+#             */
/*   Updated: 2022/03/06 21:10:46 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *dest, char const *src)
{
	size_t	len;
	char	*temp;
	size_t	i;

	len = ft_strlen(dest) + ft_strlen(src);
	temp = (char *)malloc((len + 1) * 1);
	if (!temp)
		return (0);
	i = 0;
	while (*(dest + i))
	{
		*(temp + i) = *(dest + i);
		i++;
	}
	while (*src)
	{
		*(temp + i) = *src;
		src++;
		i++;
	}
	*(temp + len) = 0;
	free(dest);
	dest = temp;
	return (dest);
}

char	*ft_strchr(char const *str, int c)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

void	ft_bzero(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*str = 0;
		i++;
		str++;
	}
}

size_t	ft_strlen(char const *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}