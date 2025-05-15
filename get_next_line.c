/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:28:31 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/15 14:45:13 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	**node;
	t_list	*new_node;
	char	*buff;
	int		a;
	int		lenght;
	
	lenght = 0;
	a = 0;
	if (node && *node)
		lenght += ft_strlen((*node) -> content);
	if (!node)
	{
		node = malloc(sizeof(t_list));
		if (!node)
			return (0);
	}
	if (fd < 0)
		return (0);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return(0);
	if (node && (*node) && check_nl((*node) -> content))
		return (returned_line(node, BUFFER_SIZE));
	while ((a = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[a] = '\0';
		new_node = ft_lstnew(ft_strdup(buff));
		if (!new_node)
		{
			ft_lstclear(node, free);
			free(buff);
			return (0);
		}
		ft_lstadd_back(node, new_node);
		lenght += a;
		if(check_nl(buff))
			break;
	}
	free(buff);
	return (returned_line(node, lenght));
}

/*int	main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	char *buff;
	if (argc)
	while ((buff = get_next_line(fd)))
	{
		printf("%s", buff);
		free(buff);
	}
}*/
