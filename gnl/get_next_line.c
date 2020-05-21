/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:24:43 by samukano          #+#    #+#             */
/*   Updated: 2018/11/15 11:24:44 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	int			tmplen;
	static char	*h[10001];
	char		buff[BUFF_SIZE + 1];
	char		*l;
	char		*tm;

	if (fd > 1000000 || fd < 0 || BUFF_SIZE < 1 || !line ||
		(!h[fd] && !(h[fd] = ft_strnew(1))))
		return (-1);
	while ((tmplen = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[tmplen] = '\0';
		h[fd] = ft_stupd(h[fd], buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (!*(tm = h[fd]) || tmplen == -1)
		return (tmplen == -1 ? -1 : 0);
	l = ft_strchr(h[fd], '\n');
	*line = ((!l) ? ft_strdup(h[fd]) : ft_strndup(h[fd], l - h[fd]));
	h[fd] = ft_strsub(h[fd], (UI)(ft_strlen(*(line)) + (l ? 1 : 0)),
	(size_t)(ft_strlen(h[fd]) - ft_strlen(*line) + (l ? 1 : 0)));
	ft_strdel(&tm);
	return (!(!h[fd] && !ft_strlen(*line)));
}

