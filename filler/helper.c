/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:55:36 by samukano          #+#    #+#             */
/*   Updated: 2018/12/12 14:55:37 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	begin_map(t_map *map)
{
	int		i;
	int		j;

	map->a = (char**)malloc(sizeof(char*) * map->n);
	i = 0;
	while (i < map->n)
	{
		map->a[i] = (char*)malloc(sizeof(char) * map->m);
		j = 0;
		while (j < map->m)
		{
			map->a[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	begin_piece(t_piece *p)
{
	int		i;
	int		j;
	char	*c;

	p->a = (char**)malloc(sizeof(char*) * p->n);
	i = 0;
	while (i < p->n)
	{
		p->a[i] = (char*)malloc(sizeof(char) * p->m);
		j = 0;
		get_next_line(0, &c);
		while (j < p->m)
		{
			p->a[i][j] = c[j];
			j++;
		}
		i++;
	}
}

void	read_map(t_map *map)
{
	char	*cols;
	char	*rows;
	int		i;
	int		j;

	i = 0;
	get_next_line(0, &cols);
	while (i < map->n)
	{
		j = 4;
		get_next_line(0, &rows);
		while (j < map->m + 4)
		{
			map->a[i][j - 4] = rows[j];
			j++;
		}
		i++;
	}
}
