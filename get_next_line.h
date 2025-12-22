/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:18:07 by rruiz             #+#    #+#             */
/*   Updated: 2025/11/17 10:18:39 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif // BUFFER_SIZE

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif // FT_GET_NEXT_LINE_H