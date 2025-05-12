/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:28:31 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/13 00:07:06 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*node;
	char	*buff;
	int		a;
	int		lenght;
	
	lenght = 0;
	if (node)
		lenght += ft_strlen(node -> content);
	if (!fd)
		return (0);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return(0);
	while ((a = read(fd, buff, BUFFER_SIZE)))
	{
		buff[a] = '\0';
		ft_lstadd_back(&node, ft_lstnew(ft_strdup(buff)));
		if(check_nl(buff))
			break;
		lenght += BUFFER_SIZE;
	}
	return (returned_line(&node, lenght + a));
}


/*int	main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);

	if (argc)
		puts(get_next_line(fd));
}*/
