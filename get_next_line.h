/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:58:38 by nkhribec          #+#    #+#             */
/*   Updated: 2019/04/18 18:33:56 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
//# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);
#endif
