/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:25:49 by samukano          #+#    #+#             */
/*   Updated: 2018/12/24 16:25:49 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			upd(int *ind, int *par, int last)
{
	int		tmp;

	tmp = last;
	while (tmp != -2)
	{
		if (par[par[tmp]] == -2)
			break ;
		ind[par[tmp]] = 1;
		tmp = par[tmp];
	}
}

void			make_path(int *par, int *to, int i, int tmp)
{
	if (tmp != -2)
		make_path(par, to, i - 1, par[tmp]);
	if (tmp == 2)
		return ;
	else
		to[i] = par[tmp];
}

t_util			get(char *w, int index)
{
	int		l;
	int		r;
	int		i;
	char	*name;
	t_util	tutil;

	name = (char*)malloc(sizeof(char) * 111111);
	i = 0;
	while (*(w + i) != ' ' && *(w + i) != '\0')
	{
		*(name + i) = *(w + i);
		i++;
	}
	i++;
	l = ft_atoi(w + i);
	while (ft_isdigit(*(w + i)))
		i++;
	r = ft_atoi(w + i);
	tutil = (t_util){name, index, l, r};
	free(name);
	return (tutil);
}

int				islink(char *w, char *e, char *r)
{
	int		i;
	int		j;
	int		ok;

	i = 0;
	ok = 0;
	j = 0;
	while (*(w + i) != '\0' && *(w + i) != '-')
	{
		*(e + i) = *(w + i);
		i++;
	}
	*(e + i) = '\0';
	if (*(w + i) == '-')
		ok = 1;
	i++;
	while (*(w + i))
		*(r + j++) = *(w + i++);
	*(r + j) = '\0';
	return (ok);
}

int				isnode(char *q)
{
	int	i;

	i = 0;
	while (*(q + i) && *(q + i) == ' ')
		i++;
	while (*(q + i) && *(q + i) != ' ')
		i++;
	while (*(q + i) && *(q + i) == ' ')
		i++;
	if (!ft_isdigit(*(q + i)))
		return (0);
	while (ft_isdigit(*(q + i)))
		i++;
	while (*(q + i) && *(q + i) == ' ')
		i++;
	if (!ft_isdigit(*(q + i)))
		return (0);
	return (1);
}
