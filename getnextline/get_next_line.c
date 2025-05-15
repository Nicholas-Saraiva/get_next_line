/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:29:41 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/15 11:28:53 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_realoc(char *str1, char *str2)
{
	int		i;
	int		size;
	char	*new_str;

	i = 0;
	size = ft_strlen(str1) + ft_strlen(str2);
	new_str = ft_strdup(str1);
	if (!new_str)
		return (0);
	free(str1);
	str1 = malloc(sizeof(char) * (size + 1));
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
	while (*str2)
	{
		str1[i] = *str2;
		i++;
		str2++;
	}
	str1[i] = '\0';
	free(new_str);
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

char	*ft_newline(char *str, char *buff)
{	
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i]  && buff[i] != '\n')
		i++;
	if (!buff[i])
		return (str);
	str[i + 1] = '\0';
	while (buff[i + j])
		j++;
	ft_memcpy(buff, buff + i, j);
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
	str = malloc (sizeof(char));
	while ((num_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num_bytes] = '\0';
		ft_realoc(str, buff);
		if (check_nl(buff))
			break ;
	}
	return (ft_newline(str, buff));
}

int	main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	char *buff;
	if (argc)
		while ((buff = get_next_line(fd)))
			continue ;
}
