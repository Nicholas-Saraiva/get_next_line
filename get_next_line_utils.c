/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:48:35 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/13 00:06:34 by nsaraiva         ###   ########.fr       */
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
	char	*line;
	t_list	*c_node;
	int		i;
	int		j;

	j = 0;
	c_node = *node;
	line = (char *)malloc((sizeof(char) * lenght) + 1);
	while(c_node)
	{
		i = 0;
		while((c_node -> content)[i] && (c_node -> content)[i] != '\n')
		{
			line[j] = (c_node -> content)[i];
			i++;
			j++;
		}
		if ((c_node -> content)[i] == '\n')
			line[i] = '\n';
		if (!(c_node -> next))
			break ;
		c_node = c_node -> next;
		ft_lstdelone(*node, free);
		*node = c_node;
	}
	modify_node(c_node, i);
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

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (0);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

