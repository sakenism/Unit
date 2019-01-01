/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:05:30 by samukano          #+#    #+#             */
/*   Updated: 2018/12/24 20:05:31 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	pr(int a, char *s)
{
	write(1, "L", 1);
	ft_putnbr(a);
	write(1, "-", 1);
	ft_putstr(s);
	write(1, "  ", 2);
}

void	leakclean(t_mane *mane)
{
	int	i;

	i = -1;
	free(mane->link);
	free(mane->end);
	free(mane->start);
	free(mane->p1);
	free(mane->p2);
	while (++i < 111111)
		free(mane->zhol->path[i]);
}

void	printw(int mur, int n, char **ch)
{
	int	i;

	i = 0;
	ft_putnbr(mur);
	ft_putstr("\n");
	while (i < n)
	{
		ft_putstr(ch[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("\n");
}

void	krut(t_mane *mane, int *first, int *last)
{
	mane->m = 0;
	mane->l = first;
	mane->r = last;
}

int		iffs(t_mane *mane, char **ch, t_graph *g)
{
	if (*mane->q == '#' && *(mane->q + 1) != '\0' && *(mane->q + 1) != '#')
	{
		ch[mane->m++] = mane->q;
		return (0);
	}
	if (!mane_mane(mane, g, mane->l, mane->r))
	{
		if (!mane_mane2(mane, g))
			return (-1);
		ch[mane->m++] = mane->q;
	}
	else
	{
		ch[mane->m++] = mane->q;
		ch[mane->m++] = mane->w;
	}
	return (1);
}
