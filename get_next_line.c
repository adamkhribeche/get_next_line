/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:57:56 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/21 00:39:04 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*void	fct(void)
{
	static int m = 0;
	//m = 0;
	m++;
	printf("%d\n", m);
}
*/
int		get_next_line(const int fd, char **line)
{
	char *p;

	p = *line;
	read(fd, p++, 1);
	while (*(p - 1) != '\n' && *(p - 1) != EOF)
	{
		read(fd, p, 1);
		p++;
	}
	//*p = '\0';
	*line = p;
	return (1);
}

int main(void)
{
	int		fd;
	char	*line;
	char	*g;

	line  = (char*)ft_memalloc(BUFF_SIZE * sizeof(*line));
	g = line;
	fd = open("adam", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", g);
	printf("-----------------\n");
	get_next_line(fd, &line);
	printf("%s", g);
	printf("-----------------\n");
	get_next_line(fd, &line);
	printf("%s", g);
	printf("-----------------\n");
	get_next_line(fd, &line);
	printf("%s", g);
	printf("-----------------\n");
	get_next_line(fd, &line);
	printf("%s", g);
	printf("-----------------\n");
	get_next_line(fd, &line);
	printf("%s", g);
	printf("-----------------\n");
	close(fd);
	return (0);
}
