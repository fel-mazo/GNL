/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 03:51:35 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/12/22 16:56:48 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		fd2;
	int		ret;
	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while ((ret = get_next_line(fd, &line)))
		{
			printf("[%s|%d]\n", line, ret);
		}
		while((ret = get_next_line(fd2, &line)) >= 0)
		{
			getchar();
			printf("[%s|%d]\n", line, ret);
		}

	}
	return (0);
}
