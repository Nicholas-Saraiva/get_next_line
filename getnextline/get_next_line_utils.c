/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:48:35 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/23 12:07:11 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *str)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

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

int	ft_strnewline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = (char *) malloc((ft_strlen(s1) + find_nl(s2) + 1) * sizeof(char));
	if (!new_s)
		return (free(s1), NULL);
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
