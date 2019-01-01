/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:59:18 by samukano          #+#    #+#             */
/*   Updated: 2018/12/24 18:59:18 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			help_mane_event2(t_mane *mane, t_graph *g, int i, int last)
{
	int	j;

	if ((mane->mur > 0 && !i) || mane->mur > mane->zhol->len[i] * i - mane->sum)
	{
		mane->mur--;
		mane->mng++;
		j = 0;
		while (++j < mane->zhol->len[i] + 1)
		{
			if (mane->used[i][j] == 0 && mane->zhol->path[i][j] != last)
			{
				mane->used[i][j] = mane->mng;
				write(1, "L", 1);
				ft_putnbr(mane->used[i][j]);
				write(1, "-", 1);
				ft_putstr(get_vertex_by_id(
				&g->vertexs, mane->zhol->path[i][j])->name);
				write(1, "  ", 2);
				break ;
			}
		}
	}
	mane->sum += mane->zhol->len[i];
}

void			jasa(t_tmpr *tr, t_graph *g, int last)
{
	while (queue_sz(&g->vertexs) > 0)
	{
		tr->tmp = g->vertexs;
		tr->used[tr->tmp->id] = 1;
		tr->ln = tr->tmp->link;
		while (tr->ln)
		{
			tr->tmp = g->vertexs;
			if (!tr->used[tr->ln->vertex->id])
			{
				tr->used[tr->ln->vertex->id] = 1;
				tr->par[tr->ln->vertex->id] = tr->tmp->id;
				if (tr->ln->vertex->id == last)
				{
					tr->ok = 1;
					break ;
				}
				tr->tmp = push(&g->vertexs, (t_util){tr->ln->vertex->name,
				tr->ln->vertex->id, tr->ln->vertex->x, tr->ln->vertex->y});
				tr->tmp->link = tr->ln->vertex->link;
			}
			tr->ln = tr->ln->next;
		}
		pop(&g->vertexs);
	}
}

void			iste(t_tmpr *tr, t_graph *g, t_vertex **head, int first)
{
	int	i;

	i = -1;
	tr->cnt = 0;
	while (++i < 111111)
	{
		tr->par[i] = -1;
		if (tr->ind[i] != 1)
			tr->used[i] = 0;
	}
	tr->tmp = *head;
	push(&g->vertexs, (t_util){tr->tmp->name,
	tr->tmp->id, tr->tmp->x, tr->tmp->y});
	g->vertexs->link = tr->tmp->link;
	tr->par[first] = -2;
	tr->ok = 0;
}

void			mane_print(t_mane *mane, t_graph *g, int kek, int i)
{
	int	j;

	while (1)
	{
		mane->ok = 0;
		i = -1;
		while (++i < kek)
		{
			j = mane->zhol->len[i];
			while (--j >= 0)
			{
				if (mane->used[i][j] != 0)
				{
					mane->ok = 1;
					pr(mane->used[i][j], get_vertex_by_id(
					&g->vertexs, mane->zhol->path[i][j + 1])->name);
					mane->used[i][j + 1] = mane->used[i][j];
					mane->used[i][j] = 0;
				}
			}
		}
		if (!mane->ok)
			break ;
		write(1, "\n", 1);
	}
}

void			last(t_mane *mane, t_graph *g, int kek)
{
	mane_event(mane, g, 0, 0);
	while (++(mane->i) < kek)
	{
		mane->j = -1;
		while (++(mane->j) < mane->zhol->len[mane->i])
		{
			if (mane->used[mane->i][mane->j] != 0)
				mane->mng = maxi(mane->mng, mane->zhol->len[mane->i] - mane->j);
			if (mane->used[mane->i][mane->j] != 0)
				break ;
		}
	}
	mane_print(mane, g, kek, -1);
	ft_putnbr(mane->cnt + mane->mng);
}
