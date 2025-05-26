/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:29:41 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/25 16:21:17 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;
	size_t			i;

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
	while (buff[i] && buff[i] != '\n')
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

char	*ft_create_line(int fd, char *buff, char *str)
{
	int	num_bytes;

	num_bytes = 1;
	while (!check_nl(buff) && num_bytes > 0)
	{
		num_bytes = read(fd, buff, BUFFER_SIZE);
		buff[num_bytes] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (0);
	}
	if (num_bytes == -1 || (num_bytes == 0 && !*str))
	{
		free(str);
		*buff = 0;
		return (0);
	}
	return (ft_newline(str, buff));
}

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0 || fd > 1024)
		return (0);
	str = malloc(1);
	if (!str)
		return (NULL);
	*str = '\0';
	if (*buff[fd])
		str = ft_strjoin(str, buff[fd]);
	if (!str)
		return (0);
	return (ft_create_line(fd, buff[fd], str));
}

/*#include <stdio.h>
int	main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	char	*buff;

	buff = 0;
	if (argc)
	{
		while (buff)
		{
			buff = get_next_line(fd);
			free(buff);
		}
	}
}*/
