/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:52:34 by juykang           #+#    #+#             */
/*   Updated: 2022/07/28 16:28:34 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_gnl
{
	int				fd;
	struct s_gnl	*next;
	char			buff[BUFFER_SIZE];
	ssize_t			start_idx;
	ssize_t			rbytes;
}	t_gnl;

char	*get_next_line(int fd);
char	*before_reading_buffer(**head, *cur, *res);
#endif