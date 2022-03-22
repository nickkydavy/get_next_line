/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:10:08 by pnimwata          #+#    #+#             */
/*   Updated: 2022/03/22 16:08:40 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// typedef struct l_list
// {
// 	char	*str;
// 	size_t	count;
// }; 


char	*get_next_line(int fd);
char	*ft_strchr(char const *s, int c);
char	*blank_str(size_t num);
char	*ft_strjoin(char const *str1, char const *str2);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t size);
size_t	ft_strlen(char const *str);

#endif
