/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:10:59 by rruiz             #+#    #+#             */
/*   Updated: 2025/11/17 10:13:11 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == (char)c)
		return (s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	var_def(char *s1, size_t *i, size_t *j, size_t *len1)
{
	*i = 0;
	*j = 0;
	*len1 = ft_strlen(s1);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	len1;

	var_def(s1, &i, &j, &len1);
	new_str = malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	while (i < len1)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	free(s1);
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
