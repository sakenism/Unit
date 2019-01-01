/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:24:11 by samukano          #+#    #+#             */
/*   Updated: 2018/12/16 15:24:11 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				g_first;
int				g_last;
int				g_kek;
char			**g_ch;

void			exec(t_tmpr *tr, int *kek)
{
	int	i;

	i = -1;
	*kek = 0;
	tr->ind = (int*)malloc(sizeof(int) * 111111);
	tr->par = (int*)malloc(sizeof(int) * 111111);
	tr->zhol = (t_paths*)malloc(sizeof(t_paths));
	tr->zhol->path = (int**)malloc(sizeof(int*) * 111111);
	tr->zhol->len = (int*)malloc(sizeof(int) * 111111);
	while (++i < 111111)
	{
		tr->zhol->path[i] = (int*)malloc(sizeof(int) * 111111);
		tr->ind[i] = 0;
	}
}

t_paths			*bfs(t_vertex **head)
{
	t_tmpr		tr;
	t_graph		g;

	exec(&tr, &g_kek);
	while (1)
	{
		iste(&tr, &g, head, g_first);
		jasa(&tr, &g, g_last);
		if (!tr.ok)
			break ;
		songi(&tr, &g_last, &g_kek);
	}
	free(tr.ind);
	free(tr.par);
	return (tr.zhol);
}

int				prep(t_mane *mane, t_graph *g, int *first, int *kek)
{
	int		i;
	int		j;

	i = -1;
	if (mane->rnum <= 0 || !mane->ter.end || !mane->ter.start)
		ft_putstr("No rooms or no start/end\n");
	if (mane->rnum <= 0 || !mane->ter.end || !mane->ter.start)
		return (0);
	mane->tmp1 = get_vertex_by_id(&g->vertexs, *first);
	mane->zhol = bfs(&mane->tmp1);
	if (!(mane->zhol->len[0]))
		ft_putstr("No path between start and = end\n");
	if (!(mane->zhol->len[0]))
		return (0);
	while (++i < *kek)
	{
		mane->used[i] = (int*)malloc(sizeof(int) * 111111);
		j = -1;
		while (++j < mane->zhol->len[i] + 1)
			mane->used[i][j] = 0;
	}
	mane->mng = 0;
	mane->cnt = 0;
	return (1);
}

void			mane_event(t_mane *mane, t_graph *g, int i, int j)
{
	while (mane->mur > 0)
	{
		mane->sum = 0;
		i = 0;
		while (i < g_kek)
		{
			help_mane_event(mane, g, i, j);
			help_mane_event2(mane, g, i, g_last);
			i++;
		}
		ft_putstr("\n");
		mane->cnt++;
	}
	mane->ok = 0;
	mane->mng = 0;
	mane->i = -1;
}

int				main(void)
{
	t_graph		g;
	t_mane		mane;
	int			put[111111];

	g_ch = (char**)malloc(sizeof(char*) * 11111);
	if (!mane_first(&mane))
		return (0);
	put[0] = 0;
	krut(&mane, &g_first, &g_last);
	while (get_next_line(0, &mane.q) > 0)
	{
		iffs(&mane, g_ch, &g);
	}
	if (!prep(&mane, &g, &g_first, &g_kek))
		return (0);
	printw(mane.mur, mane.m, g_ch);
	last(&mane, &g, g_kek);
	leakclean(&mane);
	return (0);
}
