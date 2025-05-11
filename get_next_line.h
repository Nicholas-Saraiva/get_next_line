/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:46:15 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/11 22:17:57 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
	#define BUFFER_SIZE 1
#endif
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list{
	char	*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	modify_node(t_list *node, int start);
int		check_nl(char *str);
char    *get_next_line(int fd);
char	*returned_line(t_list **node, int lenght);
#endif
