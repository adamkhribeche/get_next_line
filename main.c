/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 23:21:26 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/28 23:27:50 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;
	int 	n;

	fd = open("adam", O_RDONLY);
	while ((n = get_next_line(fd, &line)) > 0)
	{
		printf("%s", line);
		printf("\n-------n = %d----------\n",n);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
