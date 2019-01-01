/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:57:54 by samukano          #+#    #+#             */
/*   Updated: 2018/12/12 14:57:54 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_n_m(char *plateau, t_map *map)
{
	int		i;

	i = 0;
	while (*(i + plateau) && !ft_isdigit(*(i + plateau)))
		i++;
	map->n = ft_atoi(plateau + i);
	while (ft_isdigit(*(i + plateau)))
		i++;
	while (*(i + plateau) && !ft_isdigit(*(i + plateau)))
		i++;
	map->m = ft_atoi(plateau + i);
}

int		**make_value_map(t_map *map)
{
	int		i;
	int		j;
	int		**vl_map;

	i = 0;
	vl_map = (int**)malloc(sizeof(int*) * map->n);
	while (i < map->n)
	{
		j = 0;
		vl_map[i] = (int*)malloc(sizeof(int) * map->m);
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
	return (vl_map);
}

void	bfs(t_point p, t_map *map, int **vl_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->n)
	{
		j = 0;
		while (j < map->m)
		{
			if (map->a[i][j] != map->charnme && map->a[i][j] != map->charnme1)
				vl_map[i][j] = min(vl_map[i][j], abs(p.x - i) + abs(p.y - j));
			j++;
		}
		i++;
	}
}

void	clear(t_temp *tm)
{
	tm->i = -1;
	tm->ans = 0;
	tm->ok = 0;
}

int		try_put_piece_helper(t_map *m, t_piece *q, int **vl_map, t_point p)
{
	t_temp t;

	clear(&t);
	while (++(t.i) < q->n)
	{
		t.j = -1;
		while (++(t.j) < q->m)
		{
			if (q->a[t.i][t.j] == '*' && (m->a[p.x + t.i][p.y + t.j] ==
			m->charme || m->a[p.x + t.i][p.y + t.j] == m->charme1))
			{
				p.x1 = p.x + t.i;
				p.y1 = p.y + t.j;
				t.ok++;
			}
			else if (q->a[t.i][t.j] == '*' && (m->a[p.x + t.i][p.y + t.j] ==
			m->charnme || m->a[p.x + t.i][p.y + t.j] == m->charnme1))
				return (-1);
			else if (q->a[t.i][t.j] == '*' && m->a[p.x + t.i][p.y + t.j] == '.')
				t.ans += vl_map[p.x + t.i][p.y + t.j];
		}
	}
	if (t.ok != 1)
		return (-1);
	return (t.ans);
}
