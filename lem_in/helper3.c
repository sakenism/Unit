/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:24:10 by samukano          #+#    #+#             */
/*   Updated: 2018/12/24 16:24:11 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_all(t_vertex **head)
{
	t_vertex *cur;

	cur = *head;
	while (cur)
	{
		cur = cur->next;
	}
}

void			link_print_all(t_vertex **head)
{
	t_vertex	*cur;
	t_link		*ln;

	cur = (*head);
	while (cur)
	{
		ln = cur->link;
		while (ln)
		{
			ln = ln->next;
		}
		cur = cur->next;
	}
}

int				link_pop(t_link **link)
{
	t_link	*tmp;

	tmp = *link;
	if (!tmp)
		return (-1);
	tmp = (*link)->next;
	free((*link)->vertex);
	free(*link);
	*link = tmp;
	return (1);
}

t_link			*new_link(t_vertex *link)
{
	t_link *new;

	new = (t_link*)(malloc(sizeof(t_link)));
	new->vertex = link;
	new->next = NULL;
	return (new);
}

void			link_push(t_link **head, t_vertex *link)
{
	t_link *current;

	current = *head;
	if ((*head) == NULL)
	{
		(*head) = new_link(link);
		return ;
	}
	while ((*head)->next != NULL)
		*head = (*head)->next;
	(*head)->next = new_link(link);
	if (current != NULL)
		*head = current;
}
