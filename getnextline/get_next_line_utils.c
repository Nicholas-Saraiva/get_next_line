/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:48:35 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/14 17:01:12 by nsaraiva         ###   ########.fr       */
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

void	modify_node(t_list *node)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_string)
		return ;
	while ((node -> content)[i] != '\n')
		i++;
	while ((node -> content)[i])
	{
		new_string[j] = (node -> content)[i + 1];
		i++;
		j++;
	}
	new_string[j] = '\0';
	free(node -> content);
	node -> content = new_string;
	if (!*new_string)
		ft_lstclear(&node, free);
}

void	ft_lstconcat(t_list *node, char *line)
{
	int		i;
	int		j;
	char	*lst_str;

	j = 0;
	while (node)
	{
		lst_str = node -> content;
		i = 0;
		while(lst_str[i] && lst_str[i] != '\n')
		{
			line[j] = lst_str[i];
			i++;
			j++;
		}
		if (lst_str[i] == '\n')
		{
			line[j] = '\n';
			j++;
		}
		node = node -> next;
	}
	line[j] = '\0';
}

char	*returned_line(t_list **node, int lenght)
{
	char	*line;
	t_list	*c_node;

	if (!*node || !lenght)
		return (0);
	line = (char *)malloc((sizeof(char) * lenght) + 1);
	if (!line)
		return (0);
	ft_lstconcat(*node, line);
	while (*node)
	{
		c_node = *node;
		*node = (*node) -> next;
		if (!check_nl(c_node -> content))
			ft_lstdelone(c_node, free);
		else
			modify_node(c_node);
	}
	return (line);
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


void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*previus;

	if (!lst || !del)
		return ;
	next = *lst;
	previus = next;
	while (next)
	{
		next = next -> next;
		del(previus -> content);
		free(previus);
		previus = next;
	}
	*lst = NULL;
}
