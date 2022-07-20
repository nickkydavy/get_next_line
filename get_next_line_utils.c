/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:10:46 by pnimwata          #+#    #+#             */
/*   Updated: 2022/07/20 14:57:40 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	str_diff;
	size_t	i;
	size_t	count;

	str_diff = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc((sizeof(char)) * (str_diff + 1));
	if (!join || !s1 || !s2)
		return (0);
	count = 0;
	i = 0;
	while (s1[count])
		join[i++] = s1[count++];
	count = 0;
	while (s2[count])
		join[i++] = s2[count++];
	join[i] = '\0';
	return (join);
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

void	*ft_calloc(size_t n, size_t size)
{
	char	*pointer;
	size_t	count;

	pointer = malloc(n * size);
	if (!pointer)
		return (0);
	count = 0;
	while (count < (n * size))
	{
		pointer[count] = 0;
		count++;
	}
	return ((void *)pointer);
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
