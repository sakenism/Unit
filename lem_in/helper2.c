/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:22:33 by samukano          #+#    #+#             */
/*   Updated: 2018/12/24 16:22:34 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			list_remove(t_vertex **list, t_vertex *node)
{
	t_vertex *tmp;

	if (list == NULL || *list == NULL || node == NULL)
		return ;
	if (*list == node)
	{
		*list = (*list)->next;
		free(node->name);
		free(node);
		node = NULL;
	}
	else
	{
		tmp = *list;
		while (tmp->next && tmp->next != node)
			tmp = tmp->next;
		if (tmp->next)
		{
			tmp->next = node->next;
			free(node->name);
			free(node);
			node = NULL;
		}
	}
}

void			list_destroy(t_vertex **list)
{
	if (list == NULL)
		return ;
	while (*list != NULL)
	{
		list_remove(list, *list);
	}
}

int				get_id(t_vertex **head, char *name)
{
	t_vertex	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			return (tmp->id);
		}
		tmp = tmp->next;
	}
	return (-1);
}

t_vertex		*get_vertex(t_vertex **head, char *name)
{
	t_vertex	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_vertex		*get_vertex_by_id(t_vertex **head, int id)
{
	t_vertex	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->id == id)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
