/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:15:19 by samukano          #+#    #+#             */
/*   Updated: 2018/12/17 18:15:20 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/includes/libft.h"

typedef struct	s_tmpr
{
	int			used[111111];
	int			*par;
	int			*ind;
	t_paths		*zhol;
	t_vertex	*tmp;
	t_link		*ln;
	t_graph		g;
	int			ok;
	int			cnt;
	int			t;
	int			i;
}				t_tmpr;

typedef	struct	s_mane
{
	t_vertex	*tmp1;
	t_vertex	*tmp2;
	t_link		*link;
	char		*q;
	char		*w;
	char		*end;
	char		*start;
	char		*name;
	char		*p1;
	char		*p2;
	int			mur;
	int			n;
	int			m;
	int			i;
	int			j;
	int			*l;
	int			*r;
	int			put[111111];
	int			**used;
	int			cnt;
	int			index;
	int			rnum;
	int			sum;
	int			tmpmur;
	int			ans;
	int			ok;
	int			mng;
	t_paths		*zhol;
	t_error		ter;
}				t_mane;

int				pop(t_vertex **head);
void			create(t_vertex **head, t_util u);
t_vertex		*push(t_vertex **head, t_util u);
int				maxi(int a, int b);
int				queue_sz(t_vertex **head);
void			list_remove(t_vertex **list, t_vertex *node);
void			list_destroy(t_vertex **list);
int				get_id(t_vertex **head, char *name);
t_vertex		*get_vertex(t_vertex **head, char *name);
t_vertex		*get_vertex_by_id(t_vertex **head, int id);
void			print_all(t_vertex **head);
void			link_print_all(t_vertex **head);
int				link_pop(t_link **link);
t_link			*new_link(t_vertex *link);
void			link_push(t_link **head, t_vertex *link);
void			upd(int *ind, int *par, int last);
void			make_path(int *par, int *to, int i, int tmp);
t_util			get(char *w, int index);
int				islink(char *w, char *e, char *r);
int				isnode(char *q);
void			help_mane_event2(t_mane *mane, t_graph *g, int i, int last);
void			jasa(t_tmpr *tr, t_graph *g, int last);
void			iste(t_tmpr *tr, t_graph *g, t_vertex **head, int first);
void			mane_print(t_mane *mane, t_graph *g, int kek, int i);
void			last(t_mane *mane, t_graph *g, int kek);
void			help_mane_event(t_mane *mane, t_graph *g, int i, int j);
int				mane_mane2(t_mane *mane, t_graph *g);
int				mane_first(t_mane *mane);
void			songi(t_tmpr *tr, int *last, int *kek);
int				mane_mane(t_mane *mane, t_graph *g, int *first, int *last);
void			mane_event(t_mane *mane, t_graph *g, int i, int j);
void			pr(int a, char *s);
void			leakclean(t_mane *mane);
void			printw(int mur, int n, char **ch);
void			krut(t_mane *mane, int *first, int *last);
int				iffs(t_mane *mane, char **ch, t_graph *g);

#endif
