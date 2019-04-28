/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 05:30:42 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/28 21:45:59 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_append_line(char **line, char **s, const int fd)
{
	int  	len;
	char	*to_free;

	len = 0;
	to_free = s[fd];
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		s[fd] = ft_strdup(s[fd] + len + 1);
	}
	else if (s[fd][len] == '\0')
	{
		*line = ft_strsub(s[fd], 0, len);
		s[fd] = ft_strdup(s[fd] + len);
	}
	free(to_free);
}

int			get_next_line(const int fd, char **line)
{
	static char		*s[4864];
	char 			tmp[BUFF_SIZE + 1];
	ssize_t			n;
	char			*to_free;

	if (fd < 0 || !line)
		return (-1);
	while ((n = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if (s[fd] == NULL)
			s[fd] = ft_memalloc(sizeof(char));
		to_free = s[fd];
		tmp[n] = '\0';
		s[fd] = ft_strjoin(s[fd], tmp);
		free(to_free);
		if (ft_strchr(s[fd], '\n'))
			break;
	}
	if (n == -1)
		return (-1);
	if (n == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
	{
		free(s[fd]);
		return (0);
	}
	ft_append_line(line, s, fd);
	return (1);
}

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
	ft_strdel(&line);
	close(fd);
	return (0);
}
