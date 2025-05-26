/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:46:15 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/05/25 16:02:29 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	int				size;
	char			*content;
	struct s_list	*next;
}	t_list;

int		check_nl(char *str);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
#endif
