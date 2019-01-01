/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:05:46 by samukano          #+#    #+#             */
/*   Updated: 2018/11/27 22:05:46 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add(t_tetris **t, int i, int j, char c)
{
	t_tetris	*new;
	t_tetris	*tmp;

	tmp = *t;
	new = (t_tetris*)malloc(sizeof(t_tetris));
	new->x = i;
	new->y = j;
	new->c = c;
	new->next = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	tmp = NULL;
}

void	create(t_tetris **t, int i, int j, char c)
{
	t_tetris	*new;

	new = (t_tetris*)malloc(sizeof(t_tetris));
	new->x = i;
	new->y = j;
	new->c = c;
	new->next = NULL;
	*t = new;
}

int		tryy(int **a, t_t tt, t_tetris **t, int mn)
{
	t_tetris	*tmp;
	int			dx[2];
	int			i;

	i = 0;
	tmp = (*t)->next;
	while (i++ < 3 || (i = 0))
	{
		dx[0] = tmp->x - (*t)->x;
		dx[1] = tmp->y - (*t)->y;
		if (tt.qq + dx[0] < 0 || tt.qq + dx[0] >= mn || tt.ww + dx[1] < 0 ||
		tt.ww + dx[1] >= mn || a[tt.qq + dx[0]][tt.ww + dx[1]] != '.')
			return (0);
		tmp = tmp->next;
	}
	a[tt.qq][tt.ww] = (*t)->c;
	tmp = (*t)->next;
	while (i++ < 3)
	{
		dx[0] = tmp->x - (*t)->x;
		dx[1] = tmp->y - (*t)->y;
		a[tt.qq + dx[0]][tt.ww + dx[1]] = tmp->c;
		tmp = tmp->next;
	}
	return (1);
}

void	del(int **a, int x, int y, t_tetris **t)
{
	t_tetris	*tmp;
	int			dx;
	int			i;
	int			dy;

	i = 0;
	tmp = (*t)->next;
	a[x][y] = '.';
	tmp = (*t)->next;
	while (i++ < 3)
	{
		dx = tmp->x - (*t)->x;
		dy = tmp->y - (*t)->y;
		a[x + dx][y + dy] = '.';
		tmp = tmp->next;
	}
}

void	lst(t_tmp t)
{
	zapolni(t.big, t.cnt, -1, 0);
	close(t.fd);
	free(t.big);
	free(t.str);
	free(t.tmp);
}
