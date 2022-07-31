/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:51:10 by juykang           #+#    #+#             */
/*   Updated: 2022/07/30 21:32:51 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

t_gnl	*new_lst(int fd)
{
	t_gnl	*newlst;

	newlst = (t_gnl *)malloc(sizeof(t_gnl));
	if (!newlst)
		return ((void *)0);
	newlst->fd = fd;
	newlst->next = NULL;
	newlst->offset = BUFFER_SIZE;
	newlst->rbytes = BUFFER_SIZE;
	newlst->buff_idx = 0;
	return (newlst);
}

t_gnl	*find_fd_node(t_gnl **head, int fd)
{
	t_gnl	*cur;

	if (!*head)
	{
		*head = new_lst(fd);
		if (!*head)
			return ((void *)0);
	}
	cur = *head;
	while (cur)
	{
		if (cur->fd == fd)
			break ;
		if (!cur->next)
		{
			cur->next = new_lst(fd);
			if (!cur->next)
				return ((void *)0);
		}
		cur = cur->next;
	}
	return (cur);
}

char	*before_reading_buffer(t_gnl **head, t_gnl *cur, char *res)
{
	int	i;

	i = 0;
	if (cur->buff_idx < BUFFER_SIZE)
	{
		i = cur->buff_idx;
		while (i <= BUFFER_SIZE)
		{
			if (i == BUFFER_SIZE)
			{
				*res = gnl_join(cur, res);
			}
			if (cur->buff[i] == '\n')
			{
				*res = gnl_cpy(cur, res);
			}
			i++;
		}
	}
	retun (res);
}

char	*read_buffer(t_gnl **head, t_gnl *cur, char *res, int fd)
{
	if (cur->offset <= cur->rbytes)
	{
		cur->rbytes = read(fd, cur->buff, BUFFER_SIZE);
		while (cur->buff_idx <= BUFFER_SIZE)
		{
			if (cur->rbytes == 0 || cur->rbytes < BUFFER_SIZE)
			{
			}
			if (cur->buff[cur->buff_idx] == '\n')
				*res = gnl_cpy(res, cur);
			if (cur->buff_idx == BUFFER_SIZE - 1)
				*res = gnl_join(res, cur);
		}
	}
}

char	*get_next_line(int fd)
{
	static t_gnl	*head = ((void *)0);
	t_gnl			*cur;
	char			*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return ((void *)0);
	*res = (void *)0;
	cur = find_fd_node(&head, fd);
	if (before_reading_buffer)
	*res = before_reading_buffer(&head, cur, res);
	if (!res)
		return ((void *) 0);
	*res = read_buffer(&head, cur, res, fd);
	return (res);
}
