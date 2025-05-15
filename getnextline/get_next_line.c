/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:29:41 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/15 23:43:31 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*char	*ft_realoc(char *str1, char *str2)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = ft_strdup(str1);
	if (!new_str)
		return (0);
	free(str1);
	str1 = malloc(sizeof(char) * (ft_strlen(new_str) + ft_strlen(str2) + 1));
	if (!str1)
	{
		free(new_str);
		return (0);
	}
	while (new_str[i])
	{
		str1[i] = new_str[i];
		i++;
	}
	while (*str2 && *str2 != '\n')
	{
		str1[i] = *str2;
		i++;
		str2++;
	}
	if (*str2)
	{
		str1[i] = '\n';
		i++;
	}
	str1[i] = '\0';
	free(new_str);
	return (str1);
}*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;
	size_t	i;

	if (!dest && !src)
		return (0);
	c_dest = (unsigned char *) dest;
	c_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}

char	*ft_newline(char *str, char *buff)
{	
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i]  && buff[i] != '\n')
	{
		buff[i] = '\0';
		i++;
	}
	if (!buff[i])
	{
		buff[0] = '\0';
		return (str);
	}
	while (buff[i + j])
		j++;
	ft_memcpy(buff, buff + i + 1, j);
	return (str);
} 

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char	*str;
	int		num_bytes;

	num_bytes = 0;
	if (fd < 0)
		return (0);
	str = malloc(1);
	if (!str)
		return (0);
	*str = '\0';
	str = ft_strjoin(str, buff);
	while (!check_nl(buff) && (num_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	if (num_bytes == -1  || (num_bytes == 0 && !*str))
	{
		free(str);
		buff[0] = '\0';
		return (0);
	}
	return (ft_newline(str, buff));
}

/*int	main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	if (argc)
	{
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
	}
}*/
