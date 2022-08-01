/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:52:34 by juykang           #+#    #+#             */
/*   Updated: 2022/08/01 20:40:30 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
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
	int				flag;
}	t_gnl;

t_gnl	*new_lst(int fd);
t_gnl	*find_fd_node(t_gnl **head, int fd);
ssize_t	read_line(t_gnl **head, t_gnl *cur, int fd);
char	*get_next_line(int fd);
char	*get_make_line(t_gnl *head, t_gnl *cur, char **res, int flag);
char	*get_copy_line(char *res, char *cur, ssize_t len);
void	gnl_del(t_gnl **head, t_gnl *cur);
#endif