/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:32:18 by juykang           #+#    #+#             */
/*   Updated: 2022/08/01 20:35:10 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	char	*str;
	char	*str2;
	int		line1;
	int		line2;

	line1 = 1;
	line2 = 2;
	fd = open("test.txt", 0);
	fd2 = open("test2.txt", 0);
	while (1)
	{
		str = get_next_line(fd);
		str2 = get_next_line(fd2);
		if (!str && !str2)
			break ;
		printf("%d | %s", line1++, str);
		printf("%d | %s", line2++, str2);
		if (str)
			free(str);
		if (str2)
			free(str2);
	}
	close(fd);
	close(fd2);
	return (0);
}
