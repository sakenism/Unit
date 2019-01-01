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

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# define BUF_SIZE 21

typedef struct		s_tetris
{
	int				x;
	int				y;
	char			c;
	struct s_tetris	*next;
}					t_tetris;

typedef struct		s_emp
{
	int				ok;
	char			b;
}					t_emp;

typedef struct		s_tmp
{
	char	*big;
	char	*str;
	char	*tmp;
	char	c;
	int		fd;
	int		i;
	int		tint;
	int		cnt;
}					t_tmp;

typedef struct		s_t
{
	int		qq;
	int		ww;
}					t_t;

int					ft_check_symbols(char *str);
int					ft_error0(void);
int					ft_main_check(char *str);
void				lst(t_tmp t);
int					ft_check_endl(char *str);
void				fta(char **t, int n, t_tetris **tet, int m);
void				fresh(char **t, int n);
void				fresh1(t_tetris **t, int n);
int					die(int fd);
int					ft_error(void);
void				add(t_tetris **t, int i, int j, char c);
void				fresh2(int **t, int n);
void				zapolni(char *str, int tcnt, int i, int j);
int					help(t_tmp *t);
int					ft_count_words(char *s, char c);
size_t				ft_wordcount(const char *s, char c);
int					fill(int **a, t_tetris **tet, int cnt, int mn);
void				pochti_fill2(int **a, t_tetris **tet, int mn);
void				zapolni(char *str, int tcnt, int i, int j);
void				pochti_fill(int tcnt, t_tetris **tet);
int					ft_count_number(int n);
int					ft_check_contact(char *s);
int					tryy(int **a, t_t tt, t_tetris **t, int mn);
void				pochti_fill(int tcnt, t_tetris **tet);
void				del(int **a, int x, int y, t_tetris **t);
int					ft_count_words(char *s, char c);
char				**ft_strsplit(char const *s, char c);
void				create(t_tetris **t, int i, int j, char c);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
int					ft_sqrt(int n);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strndup(const char *s1, size_t sz);

#endif
