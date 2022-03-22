/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:10:46 by pnimwata          #+#    #+#             */
/*   Updated: 2022/03/22 14:18:38 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_strchr(char const *s, int c)
{
	size_t	i;
	
	i = 0;
	while (*(s + i) != 0)
	{
		if (*(s + i) == (char)c)
			return ((char)*(s + i));
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (!mem)
		return (0);
	ft_bzero(mem, count * size);
	return (mem);
}

void	ft_bzero(void *s, size_t size)
{
	char	*str;
	size_t	i;
	
	i = 0;
	str = (char *)s;
	while (i < size)
	{
		*(str + i) = 0;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)ft_calloc (size + 1, sizeof (char));
	if (!new_s)
		return (0);
	i = 0;
	j = 0;
	while (*(s1 + j) != '\0')
	{
		*(new_s + i) = *(s1 + j);
		i++;
		j++;
	}
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(new_s + i) = *(s2 + j);
		i++;
		j++;
	}
	*(new_s + i) = '\0';
	return (new_s);
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
