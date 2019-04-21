/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:57:56 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/21 04:35:27 by nkhribec         ###   ########.fr       */
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
	char		*p;
	ssize_t		n;

	p = *line;
	n = read(fd, p, 1);
	if (n == 0)
		return (0);
	if (*p == '\n')
		return (1);
	if (n == 1)
	{
		(*line)++;
		get_next_line(fd, line);
		return (1);
	}
	else
		return (-1);
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
