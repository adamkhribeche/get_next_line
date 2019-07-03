/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 23:21:26 by nkhribec          #+#    #+#             */
/*   Updated: 2019/07/03 19:29:19 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, char **av)
{
	int		fd1;
	char	*line;
	int 	n;
	int 	i;

	(void)ac;
	fd1 = open(av[1], O_RDONLY);
	
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
	close(fd1);
	return (0);
}
