/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:51:39 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/16 15:55:16 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_error(void)
{
	write(1, "error\n", 6);
	return (-2);
}

int	ft_error0(void)
{
	write(1, "error\n", 6);
	return (0);
}

int	die(int fd)
{
	if (fd < 0)
		close(fd);
	write(1, "usage: ./fillit source_file\n", 28);
	return (0);
}
