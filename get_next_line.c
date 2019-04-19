/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:57:56 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/19 04:40:11 by nkhribec         ###   ########.fr       */
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
	while (*(p - 1) != '\n' && *(p - 1) != EOF)
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

	line  = (char*)ft_memalloc(1000 * sizeof(*line));
	fd = open("adam", O_RDONLY);
	//printf("%d\n", fd);
	get_next_line(fd, &line);
	//read(fd, line, 50);
	//line[5] = '\0';
	printf("%s", line);
	close(fd);
	return (0);
}
