/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:29:41 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/14 22:55:49 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_realoc(char *str1, char *str2)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = ft_strdup(str1);
	if (*str1)
		free(str1)
	str1 = malloc((sizeof(char) * ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (!str1)
		return (0);
	while (*new_str)
	{
		str1[i++] = *new_str;
		new_str++;
	}
	while (*str2)
	{
		str1[i++] = *str2;
		str1++;
	}
	str1[i] = '\0';
	return (i);
}

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

char	*ft_newline(char , char *buff, int lenght)
{	
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * lenght);
	if (!line)
		return (0);
	while (buff[i]  && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (!buff[i])
	{
		free(buff);
		return (line);
	}
	while (buff[i + j])
		j++;
	ft_memcpy(buff, buff + i, j);
	return (line);
} 

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char	*str;
	int		lenght;

	lenght = 0;
	if (fd < 0)
		return (0);
	str = malloc (sizeof(char));
	while (read(fd, buff, BUFFER_SIZE) > 0 && !check_nl(buff))
		lenght = ft_realoc(str, buff);
	return (ft_newline(str, buff, lenght));
}

int	main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	char *buff;
	if (argc)
	{
		while ((buff = get_next_line(fd)))
		{
			free(buff);
		}
	}
}
