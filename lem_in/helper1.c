/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:17:58 by samukano          #+#    #+#             */
/*   Updated: 2018/12/24 16:17:59 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				pop(t_vertex **head)
{
	t_vertex	*tmp;
	int			id;

	tmp = *head;
	id = tmp->id;
	if (!tmp)
		return (-1);
	tmp = (*head)->next;
	free((*head)->name);
	free(*head);
	*head = tmp;
	return (id);
}

void			create(t_vertex **head, t_util u)
{
	t_vertex *new;

	new = (t_vertex*)malloc(sizeof(t_vertex));
	new->id = u.id;
	new->used = 0;
	new->link = NULL;
	new->full = 0;
	new->x = u.x;
	new->y = u.y;
	new->name = ft_strdup(u.name);
	new->next = NULL;
	*head = new;
}

t_vertex		*push(t_vertex **head, t_util u)
{
	t_vertex	*new;
	t_vertex	*tmp;

	tmp = *head;
	create(&new, u);
	if (!(*head))
		*head = new;
	else
	{
		while ((*head)->next)
			(*head) = (*head)->next;
		(*head)->next = new;
		*head = tmp;
	}
	return (new);
}

int				maxi(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int				queue_sz(t_vertex **head)
{
	t_vertex	*tmp;
	int			cnt;

	cnt = 0;
	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}
