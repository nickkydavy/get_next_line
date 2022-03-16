/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:10:08 by pnimwata          #+#    #+#             */
/*   Updated: 2022/03/06 21:10:08 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int);
char	*ft_strnew(int);
char	*ft_strjoin(char const *str1, char const *str2);
void	*ft_memset(void *s, int c, size_t size);
size_t	ft_strlen(char const *str);

#endif