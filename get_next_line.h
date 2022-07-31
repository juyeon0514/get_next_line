/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:52:34 by juykang           #+#    #+#             */
/*   Updated: 2022/07/30 21:16:23 by juykang          ###   ########seoul.kr  */
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
	char			*new;
	ssize_t			offset;
	ssize_t			rbytes;
	ssize_t			buff_idx;
}	t_gnl;

char	*get_next_line(int fd);
char	*before_reading_buffer(t_gnl **head, t_gnl *cur, char *res);
char	*gnl_join(char *res, char *cur);
char	*gnl_cpy(char *res, t_gnl *cur);
#endif