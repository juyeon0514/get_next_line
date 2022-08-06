/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:32:18 by juykang           #+#    #+#             */
/*   Updated: 2022/08/06 16:56:32 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;
	int		line1;

	line1 = 1;
	fd = open("test.txt", 0);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%d | %s", line1++, str);
		close(fd);
		if (str)
			free(str);
	}
	close(fd);
	return (0);
}
