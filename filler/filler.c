/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:35:48 by samukano          #+#    #+#             */
/*   Updated: 2018/12/09 13:35:48 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		g_x;
int		g_y;
int		g_cnt;

int		doo(t_temp t)
{
	if (t.ans == INF)
	{
		g_x = 0;
		g_y = 0;
		return (0);
	}
	g_x = t.final.x;
	g_y = t.final.y;
	return (t.ans);
}

int		try_put_piece(t_map *map, t_piece *p, int **vl_map)
{
	t_temp	t;

	t.i = -1;
	t.ans = INF;
	while (++t.i < map->n - p->n + 1)
	{
		t.j = -1;
		while (++t.j < map->m - p->m + 1)
		{
			t.pnt.x = t.i;
			t.pnt.y = t.j;
			t.pnt.fm = -1;
			t.tmp = try_put_piece_helper(map, p, vl_map, t.pnt);
			if ((t.tmp != -1 && t.tmp < t.ans && !(t.i == 0 && t.j == 0)))
			{
				t.final.x = t.i;
				t.final.y = t.j;
				t.final.fm = t.tmp;
				t.ans = t.tmp;
			}
		}
	}
	return (doo(t));
}

void	lst(t_mn *mn)
{
	int	i;

	i = 0;
	try_put_piece(&mn->map, &mn->p, mn->value_map);
	ft_putnbr(g_x);
	ft_putchar(' ');
	ft_putnbr(g_y);
	ft_putchar('\n');
	free(mn->plateau);
	free(mn->piece);
	while (i < mn->p.n)
	{
		free(mn->p.a[i]);
		i++;
	}
	free(mn->p.a);
	mn->piece = (char*)malloc(200000);
	mn->plateau = (char*)malloc(200000);
	g_cnt++;
}

void	all_mn(t_mn *mn)
{
	while ((!(g_x == 0 && g_y == 0)) || g_cnt == 0)
	{
		get_next_line(0, &mn->plateau);
		get_n_m(mn->plateau, &mn->map);
		g_x = -1;
		if (!g_cnt)
			begin_map(&mn->map);
		read_map(&mn->map);
		get_next_line(0, &mn->piece);
		get_piece(mn->piece, &mn->p);
		if (!g_cnt)
			mn->value_map = make_value_map(&mn->map);
		update_value_map(&mn->map, mn->value_map);
		lst(mn);
	}
}

int		main(void)
{
	t_mn	mn;

	mn.plateau = (char*)malloc(200000);
	mn.exec1 = (char*)malloc(200000);
	mn.piece = (char*)malloc(200000);
	get_next_line(0, &mn.exec1);
	exec(&mn.map, mn.exec1[10]);
	all_mn(&mn);
}
