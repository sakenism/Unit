/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:10:59 by samukano          #+#    #+#             */
/*   Updated: 2018/11/28 17:49:19 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int g_cnt;

int		ft_main_check(char *str)
{
	if ((ft_check_symbols(str)) == 1 || (ft_check_endl(str)) == 1 ||
		ft_check_contact(str) == 0)
		return (ft_error());
	return (0);
}

int		fill(int **a, t_tetris **tet, int cnt, int mn)
{
	t_t	t;
	int	q[2];

	if (cnt == g_cnt)
		return (1);
	q[0] = 0;
	while (q[0]++ < mn)
	{
		q[1] = 0;
		while (q[1]++ < mn)
		{
			t.qq = q[0] - 1;
			t.ww = q[1] - 1;
			if (a[q[0] - 1][q[1] - 1] == '.' && tryy(a, t, tet, mn))
			{
				if (!fill(a, tet + 1, cnt + 1, mn))
					del(a, q[0] - 1, q[1] - 1, tet);
				else
					return (1);
			}
		}
	}
	return (0);
}

void	zapolni(char *str, int tcnt, int i, int j)
{
	t_tetris	**tet;
	t_emp		smith;
	char		**qwe;

	qwe = ft_strsplit(str, '\n');
	tet = (t_tetris**)malloc(sizeof(t_tetris*) * tcnt);
	while (++i < 4 * tcnt)
	{
		if (i % 4 == 0)
			smith.ok = 0;
		j = 0;
		while (j++ < 4)
		{
			smith.b = qwe[i][j - 1];
			if (smith.b == '#')
			{
				if (!smith.ok && (++(smith.ok)))
					create((tet + i / 4), i, j - 1, i / 4 + 'A');
				else
					add((tet + i / 4), i, j - 1, i / 4 + 'A');
			}
		}
	}
	pochti_fill(tcnt, tet);
	fta(qwe, 111111, tet, tcnt);
}

void	pochti_fill2(int **a, t_tetris **tet, int mn)
{
	int	i;
	int	j;

	while (fill(a, tet, 0, mn) != 1)
	{
		mn++;
		i = 0;
		while (i++ < mn)
		{
			j = 0;
			while (j < mn)
				a[i - 1][j++] = '.';
		}
	}
	i = 0;
	while (i++ < mn)
	{
		j = 0;
		while (j < mn)
			ft_putchar(a[i - 1][j++]);
		ft_putchar('\n');
	}
}

void	pochti_fill(int tcnt, t_tetris **tet)
{
	int	mn;
	int	i;
	int	j;
	int **a;

	a = (int**)malloc(sizeof(int*) * 1001);
	g_cnt = tcnt;
	i = 0;
	while (i < 1001)
		*(a + i++) = (int*)malloc(sizeof(int) * 1001);
	mn = ft_sqrt(tcnt * 4);
	i = 0;
	while (i++ < mn)
	{
		j = 0;
		while (j < mn)
			a[i - 1][j++] = '.';
	}
	pochti_fill2(a, tet, mn);
	i = -1;
	fresh2(a, 1001);
}
