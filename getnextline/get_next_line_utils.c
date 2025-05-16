/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:48:35 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/16 12:15:23 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strdup(char	*src)
{
	char	*duplicated;
	char	*start;

	duplicated = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!duplicated)
		return (0);
	start = duplicated;
	while (*src)
	{
		*duplicated = *src;
		duplicated++;
		src++;
	}
	*duplicated = '\0';
	return (start);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_s)
		return (0);
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		new_s[i] = *s2;
		s2++;
		i++;
		if (new_s[i - 1] == '\n')
			break ;
	}
	new_s[i] = '\0';
	free(s1);
	return (new_s);
}
