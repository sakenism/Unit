/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:13:22 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/18 19:52:46 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <string.h>
# include "libft/includes/get_next_line.h"
# include <stdarg.h>
# include <unistd.h>

# define UI unsigned int
# define INF 100000007

int						min(int a, int b);
int						abs(int a);
void					begin_map(t_map *map);
void					begin_piece(t_piece *p);
void					read_map(t_map *map);
void					get_n_m(char *plateau, t_map *map);
int						**make_value_map(t_map *map);
void					bfs(t_point p, t_map *map, int **vl_map);
int						try_put_piece_helper(t_map *map, t_piece *p,
int **vl_map, t_point pnt);
void					update_value_map(t_map *map, int **vl_map);
void					reset_value_map(t_map *map, int **vl_map);
int						min_distance(t_map *map, int **vl_map);
void					get_piece(char *piece, t_piece *p);
void					exec(t_map *map, char c);

typedef struct			s_temp
{
	int				i;
	int				j;
	int				ok;
	int				ans;
	int				tmp;
	t_point			pnt;
	t_point			final;
}						t_temp;

typedef struct			s_mn
{
	char	*plateau;
	char	*exec1;
	char	*exec2;
	char	*piece;
	int		**value_map;
	t_map	map;
	t_piece	p;
}						t_mn;

#endif
