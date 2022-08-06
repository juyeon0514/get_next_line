/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:51:54 by juykang           #+#    #+#             */
/*   Updated: 2022/08/06 16:52:02 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_gnl
{
	int				fd;
	struct s_gnl	*next;
	char			buff[BUFFER_SIZE];
	ssize_t			offset;
	ssize_t			rbytes;
	ssize_t			len;
	ssize_t			res_len;
}	t_gnl;

char	*get_next_line(int fd);
t_gnl	*new_lst(int fd);
t_gnl	*find_fd_node(t_gnl **head, t_gnl **cur, int fd);
ssize_t	read_line(t_gnl **head, char *res, t_gnl *cur, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	gnl_del(t_gnl **head, t_gnl *cur);
#endif