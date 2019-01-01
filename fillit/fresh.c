/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:59:09 by samukano          #+#    #+#             */
/*   Updated: 2018/11/28 19:59:10 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fresh(char **t, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		free(*(t + i));
		*(t + i) = NULL;
	}
	free(t);
	t = NULL;
}

void	fresh2(int **t, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		free(*(t + i));
		*(t + i) = NULL;
	}
	free(t);
	t = NULL;
}

void	fresh1(t_tetris **t, int n)
{
	int			i;

	i = -1;
	while (++i < n)
	{
		free((*(t + i))->next->next->next);
		(*(t + i))->next->next->next = NULL;
		free((*(t + i))->next->next);
		(*(t + i))->next->next = NULL;
		free((*(t + i))->next);
		(*(t + i))->next = NULL;
		free((*(t + i)));
		(*(t + i)) = NULL;
	}
	free(t);
	t = NULL;
}

void	fta(char **t, int n, t_tetris **tet, int m)
{
	fresh(t, n);
	fresh1(tet, m);
}
