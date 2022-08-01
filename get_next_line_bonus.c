/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:51:10 by juykang           #+#    #+#             */
/*   Updated: 2022/08/01 20:31:29 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	newlst->res_len = 0;
	newlst->len = 1;
	newlst->flag = 1;
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

ssize_t	read_line(t_gnl **head, t_gnl *cur, int fd)
{
	cur->rbytes = read(fd, cur->buff, BUFFER_SIZE);
	if (cur->rbytes < 0)
	{
		gnl_del(head, cur);
		return (0);
	}
	cur->offset = 0;
	cur->len = 1;
	return (1);
}

char	*get_make_line(t_gnl *head, t_gnl *cur, char **res, int flag)
{
	char	*new_line;

	new_line = malloc(cur->res_len + cur->len + 1);
	if (!new_line)
	{
		gnl_del(&head, cur);
		return ((void *)0);
	}
	if (*res)
	{
		get_copy_line(new_line, *res, cur->res_len);
		free (*res);
	}
	get_copy_line(&new_line[cur->res_len], \
		&cur->buff[cur->offset - cur->len + 1], cur->len);
	new_line[cur->res_len + cur->len] = '\0';
	cur->res_len += cur->len;
	if (flag)
	{
		cur->res_len = 0;
		cur->offset += 1;
	}
	*res = new_line;
	return (new_line);
}

char	*get_next_line(int fd)
{
	static t_gnl	*head = ((void *)0);
	t_gnl			*cur;
	char			*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return ((void *)0);
	res = (void *)0;
	cur = find_fd_node(&head, fd);
	while (cur->offset <= BUFFER_SIZE)
	{
		if (cur->offset == BUFFER_SIZE)
			read_line(&head, cur, fd);
		if (cur->rbytes < BUFFER_SIZE && cur->offset == cur->rbytes)
		{
			gnl_del(&head, cur);
			return (res);
		}
		if (cur->buff[cur->offset] == '\n')
			return (get_make_line(head, cur, &res, 1));
		if (cur->offset == cur->rbytes - 1)
			if (!get_make_line(head, cur, &res, 0))
				return ((void *) 0);
		cur->offset++;
		cur->len++;
	}
	return (res);
}
