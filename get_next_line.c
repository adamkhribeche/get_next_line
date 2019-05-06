/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 05:30:42 by nkhribec          #+#    #+#             */
/*   Updated: 2019/05/06 17:01:54 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_append_line(char **line, char **s, const int fd)
{
	int				len;
	char			*to_free;

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
	ft_strdel(&to_free);
	return (1);
}

static ssize_t		ft_get_untel_newline(char **s, const int fd, char *tmp)
{
	ssize_t			n;
	char			*to_free;

	n = 1;
	if ((ft_strchr(s[fd], '\n') == NULL))
	{
		while ((n = read(fd, tmp, BUFF_SIZE)) > 0)
		{
			to_free = s[fd];
			tmp[n] = '\0';
			s[fd] = ft_strjoin(s[fd], tmp);
			ft_strdel(&to_free);
			if (ft_strchr(s[fd], '\n'))
				break ;
		}
	}
	return (n);
}

int					get_next_line(const int fd, char **line)
{
	static char		*s[MAX_FD];
	char			tmp[BUFF_SIZE + 1];
	ssize_t			n;

	if (fd < 0 || fd > MAX_FD || !line || BUFF_SIZE < 0)
		return (-1);
	if (s[fd] == NULL)
		s[fd] = ft_memalloc(sizeof(char));
	n = ft_get_untel_newline(s, fd, tmp);
	if (n == -1)
		return (-1);
	if (n == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
	{
		ft_strdel(&s[fd]);
		return (0);
	}
	return (ft_append_line(line, s, fd));
}
