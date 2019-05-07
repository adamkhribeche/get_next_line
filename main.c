/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 23:21:26 by nkhribec          #+#    #+#             */
/*   Updated: 2019/05/04 14:05:15 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line;
	int 	n;
	int 	i;

	fd1 = open("file1", O_RDONLY);
	fd2 = open("file2", O_RDONLY);
	fd3 = open("file3", O_RDONLY);
	fd4 = open("file4", O_RDONLY);
	
	i = 0;
	printf("\n\n*******file1*******\n");
	while (i < 6)
	{
		n = get_next_line(fd1, &line);
		printf("%s", line);
		printf("\n-------n = %d----------\n",n);
		ft_strdel(&line);
		i++;
	}
	i = 0;
	printf("\n\n*******file2*******\n");
	while (i < 6)
	{
		n = get_next_line(fd2, &line);
		printf("%s", line);
		printf("\n-------n = %d----------\n",n);
		ft_strdel(&line);
		i++;
	}
	printf("\n\n*******file1*******\n");
	i = 0;
	while (i < 6)
	{
		n = get_next_line(fd1, &line);
		printf("%s", line);
		printf("\n-------n = %d----------\n",n);
		ft_strdel(&line);
		i++;
	}
	printf("\n\n*******file3*******\n");
	i = 0;
	while (i < 6)
	{
		n = get_next_line(fd3, &line);
		printf("%s", line);
		printf("\n-------n = %d----------\n",n);
		ft_strdel(&line);
		i++;
	}
	printf("\n\n*******file4*******\n");
	i = 0;
	while (i < 6)
	{
		n = get_next_line(fd4, &line);
		printf("%s", line);
		printf("\n-------n = %d----------\n",n);
		ft_strdel(&line);
		i++;
	}
	printf("\n\n*******file3*******\n");
	i = 0;
	while (i < 6)
	{
		n = get_next_line(fd3, &line);
		printf("%s", line);
		printf("\n-------n = %d----------\n",n);
		ft_strdel(&line);
		i++;
	}

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
