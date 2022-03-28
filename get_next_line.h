/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnimwata <pnimwata@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:10:08 by pnimwata          #+#    #+#             */
/*   Updated: 2022/03/28 13:33:37 by pnimwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*set_all_str(int fd, char *buffer);
char	*ft_strcat(char *dest, char const *src);
char	*ft_strchr(char const *str, int c);
void	ft_bzero(char *str, size_t size);
size_t	ft_strlen(char const *str);

#endif
