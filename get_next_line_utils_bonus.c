/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:38:04 by juykang           #+#    #+#             */
/*   Updated: 2022/08/01 22:59:48 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_copy_line(char *dst, char *src, ssize_t len)
{
	ssize_t			i;

	if (!(dst && src))
	{
		return ((void *)0);
	}
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void	gnl_del(t_gnl **head, t_gnl *cur)
{
	t_gnl	*temp;

	if (!*head)
		return ;
	if (*head == cur)
	{
		*head = cur->next;
		free (cur);
		return ;
	}
	temp = *head;
	while (temp->next)
	{
		if (temp->next == cur)
		{
			temp->next = cur->next;
			free(cur);
			return ;
		}
		temp = temp->next;
	}
	return ;
}
