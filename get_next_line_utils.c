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

char	*ft_strnew(int num)
{
	char	*str;
	
	str = (char *)malloc(num * sizeof (char));
	if (!str)
		return (0);
	str = ft_memset(str, 0, num * 1);
	return (str);
}

void	*ft_memset(void *s, int c, size_t size)
{
	char			*str;
	unsigned int	i;
	
	if (!s)
		return (0);
	i = 0;
	str = (char *)s;
	while (i < size)
	{
		*(str + i) = c;
		i++;
	}
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)malloc ((size + 1) * sizeof (char));
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
	while (str)
	{
		count++;
		str++;
	}
	return (count);
}