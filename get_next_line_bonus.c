/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:51:10 by juykang           #+#    #+#             */
/*   Updated: 2022/08/06 16:49:04 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_make_line(t_gnl **head, t_gnl *cur, char **res, int flag)
{
	char	*new_line;

	new_line = malloc(sizeof(char) * (cur->res_len + cur->len + 1));
	if (!new_line)
	{
		gnl_del(head, cur);
		free(*res);
		return ((void *)0);
	}
	if (*res)
	{
		ft_strlcpy(new_line, *res, cur->res_len + 1);
		free (*res);
	}
	ft_strlcpy(&new_line[cur->res_len],
		&cur->buff[cur->offset - cur->len + 1], cur->len + 1);
	cur->res_len += cur->len;
	if (flag)
	{
		cur->res_len = 0;
		cur->offset += 1;
	}
	cur->len = 1;
	*res = new_line;
	return (new_line);
}

char	*get_next_line(int fd)
{
	static t_gnl	*head = ((void *)0);
	t_gnl			*cur;
	char			*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || !find_fd_node(&head, &cur, fd))
		return ((void *)0);
	res = (void *)0;
	while (1)
	{
		if (cur->offset == BUFFER_SIZE)
			if (!read_line(&head, res, cur, fd))
				return ((void *) 0);
		if (cur->rbytes < BUFFER_SIZE && cur->offset == cur->rbytes)
		{
			gnl_del(&head, cur);
			return (res);
		}
		if (cur->buff[cur->offset] == '\n')
			return (get_make_line(&head, cur, &res, 1));
		if (cur->offset == cur->rbytes - 1)
			if (!get_make_line(&head, cur, &res, 0))
				return ((void *) 0);
		cur->offset++;
		cur->len++;
	}
}
