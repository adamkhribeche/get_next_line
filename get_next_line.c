/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:57:56 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/18 23:13:07 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *p;
	//int index;

	//index = 0;
	p = *line;
	read(fd, p++, 1);
	while (*p != '\n' && *p != EOF)
	{
		read(fd, p, 1);
		p++;
	//	index++;
	}
	//*p = '\0';
	//*line = p;
	return (1);
}

int main(void)
{
	int		fd;
	char	*line;

	line  = (char*)malloc(1000 * sizeof(*line));
	fd = open("adam", O_RDWR);
	//printf("%d\n", fd);
	get_next_line(fd, &line);
	//read(fd, line, 50);
	//line[5] = '\0';
	printf("%s", line);
	close(fd);
	return (0);
}
