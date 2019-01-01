/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:59:58 by samukano          #+#    #+#             */
/*   Updated: 2018/12/12 14:59:59 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	update_value_map(t_map *map, int **vl_map)
{
	int		i;
	int		j;
	t_point	p;

	i = 0;
	while (i < map->n)
	{
		j = 0;
		while (j < map->m)
		{
			if (map->a[i][j] == map->charnme || map->a[i][j] == map->charnme1)
			{
				p.x = i;
				p.y = j;
				vl_map[i][j] = 0;
				bfs(p, map, vl_map);
			}
			j++;
		}
		i++;
	}
}

void	reset_value_map(t_map *map, int **vl_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->n)
	{
		j = 0;
		while (j < map->m)
		{
			if (map->a[i][j] == map->charnme || map->a[i][j] == map->charnme1)
				vl_map[i][j] = 0;
			else
				vl_map[i][j] = INF;
			j++;
		}
		i++;
	}
	update_value_map(map, vl_map);
}

int		min_distance(t_map *map, int **vl_map)
{
	int		i;
	int		j;
	int		mini;

	i = 0;
	mini = 0;
	while (i < map->n)
	{
		j = 0;
		while (j < map->m)
		{
			if (map->a[i][j] == map->charme || map->a[i][j] == map->charme1)
				mini += vl_map[i][j];
			j++;
		}
		i++;
	}
	return (mini);
}

void	exec(t_map *map, char c)
{
	if (c == '2')
	{
		map->charme = 'X';
		map->charme1 = 'x';
		map->charnme = 'O';
		map->charnme1 = 'o';
	}
	else
	{
		map->charme = 'O';
		map->charme1 = 'o';
		map->charnme = 'X';
		map->charnme1 = 'x';
	}
}

void	get_piece(char *piece, t_piece *p)
{
	int		i;

	i = 0;
	while (*(piece + i) && !ft_isdigit(*(piece + i)))
		i++;
	p->n = ft_atoi(piece + i);
	while (ft_isdigit(*(piece + i)))
		i++;
	while (*(piece + i) && !ft_isdigit(*(piece + i)))
		i++;
	p->m = ft_atoi(piece + i);
	begin_piece(p);
}
