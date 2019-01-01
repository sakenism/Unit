/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:55:39 by samukano          #+#    #+#             */
/*   Updated: 2018/12/24 18:55:39 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			help_mane_event(t_mane *mane, t_graph *g, int i, int j)
{
	j = mane->zhol->len[i] - 1;
	while (j >= 0)
	{
		if (mane->used[i][j] != 0)
		{
			write(1, "L", 1);
			ft_putnbr(mane->used[i][j]);
			write(1, "-", 1);
			ft_putstr(get_vertex_by_id(&g->vertexs,
			mane->zhol->path[i][j + 1])->name);
			write(1, "  ", 2);
			mane->used[i][j + 1] = mane->used[i][j];
			mane->used[i][j] = 0;
		}
		j--;
	}
}

int				mane_mane2(t_mane *mane, t_graph *g)
{
	if (islink(mane->q, mane->p1, mane->p2))
	{
		if (mane->rnum <= 1)
			write(1, "not enough rooms\n", 17);
		if (mane->rnum <= 1)
			return (0);
		mane->tmp1 = get_vertex(&g->vertexs, mane->p1);
		mane->tmp2 = get_vertex(&g->vertexs, mane->p2);
		link_push(&mane->tmp1->link, mane->tmp2);
		link_push(&mane->tmp2->link, mane->tmp1);
		mane->index++;
		return (1);
	}
	else if (isnode(mane->q))
	{
		push(&g->vertexs, get(mane->q, mane->index));
		mane->rnum++;
		mane->index++;
	}
	return (1);
}

int				mane_first(t_mane *mane)
{
	mane->link = (t_link*)malloc(sizeof(t_link) * 111111);
	mane->end = (char*)malloc(sizeof(char) * 111111);
	mane->start = (char*)malloc(sizeof(char) * 111111);
	mane->used = (int**)malloc(sizeof(int*) * 111111);
	mane->p1 = (char*)malloc(sizeof(char) * 111111);
	mane->p2 = (char*)malloc(sizeof(int*) * 111111);
	mane->index = 0;
	mane->rnum = 0;
	ft_strcpy(mane->end, "##end");
	ft_strcpy(mane->start, "##start");
	get_next_line(0, &mane->q);
	mane->mur = ft_atoi(mane->q);
	if (mane->mur <= 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	free(mane->q);
	return (1);
}

void			songi(t_tmpr *tr, int *last, int *kek)
{
	int		i;

	tr->t = *last;
	while (tr->par[tr->t] != -2)
	{
		tr->t = tr->par[tr->t];
		tr->cnt++;
	}
	tr->t = *last;
	tr->zhol->len[(*kek)] = tr->cnt;
	i = 0;
	tr->zhol->path[(*kek)][tr->cnt] = *last;
	while (tr->t != -2)
	{
		tr->t = tr->par[tr->t];
		tr->zhol->path[(*kek)][tr->cnt - i - 1] = tr->t;
		i++;
	}
	upd(tr->ind, tr->par, *last);
	(*kek)++;
}

int				mane_mane(t_mane *mane, t_graph *g, int *first, int *last)
{
	if (ft_strcmp(mane->q, mane->end) == 0)
	{
		mane->ter.end = 1;
		if (get_next_line(0, &mane->w) > 0)
		{
			*last = mane->index;
			push(&g->vertexs, (t_util)get(mane->w, mane->index++));
			mane->rnum++;
		}
		return (1);
	}
	else if (ft_strcmp(mane->q, mane->start) == 0)
	{
		mane->ter.start = 1;
		if (get_next_line(0, &mane->w) > 0)
		{
			*first = mane->index;
			push(&g->vertexs, get(mane->w, mane->index++));
			mane->rnum++;
		}
		return (1);
	}
	return (0);
}
