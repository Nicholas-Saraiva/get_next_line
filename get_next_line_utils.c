/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:48:35 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/11 22:18:47 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*next_node;

	next_node = *lst;
	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	while (next_node -> next)
		next_node = next_node -> next;
	next_node -> next = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

void	modify_node(t_list *node, int start)
{
	char	*new_string;
	int		i;

	i = 0;
	new_string = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_string)
		return ;
	while ((node -> content)[i])
	{
		if (i < (BUFFER_SIZE - start) - 1)
			new_string[i] = (node -> content)[start + i];
		else
			new_string[i] = '\0'; 
		i++;
	} 
	free(node -> content);
	node -> content = new_string;
}

char	*returned_line(t_list **node, int lenght)
{
	t_list	*c_node;
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * lenght);
	while(node)
	{
		i = 0;
		while((*node -> content)[i] && (*node -> content)[i] != '\n')
		{
			line[i] = (*node -> content)[i];
			i++;
		}
		if ((*node -> content)[i] == '\n')
			line[i] = '\n';
		if (!(*node -> next))
			break ;
		c_node = *node -> next;
		ft_lstdelone(*node, free);
		node = c_node;
	}
	modify_node(node, i);
	return (line);
}

int	check_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
