/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:42:58 by samukano          #+#    #+#             */
/*   Updated: 2018/11/09 21:30:30 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 150

typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

typedef struct			s_map
{
	int				n;
	int				m;
	char			charme;
	char			charme1;
	char			charnme;
	char			charnme1;
	char			**a;
}						t_map;

typedef struct			s_piece
{
	int				n;
	int				m;
	char			**a;
}						t_piece;

typedef struct			s_point
{
	int				x;
	int				y;
	int				fm;
	int				x1;
	int				y1;
	int				fm1;
}						t_point;

typedef struct			s_gnl
{
	char			*str;
	int				fd;
	struct s_gnl	*next;
}						t_gnl;

typedef struct			s_file
{
	int				fd;
	size_t			count;
	char			buff[BUFF_SIZE + 1];
	struct s_file	*next;
}						t_file;

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *restrict dst,
	const void *restrict src, size_t n);
void					*ft_memccpy(void *restrict dst,
	const void *restrict src, int c, size_t n);
void					*ft_memmove(void *dst,
const void *src, size_t len);
void					*ft_memchr(const void *s,
int c, size_t n);
int						ft_memcmp(const void *s1,
const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst,
const char *src);
char					*ft_strncpy(char *dst,
const char *src, size_t len);
char					*ft_strcat(char *restrict s1,
const char *restrict s2);
char					*ft_strncat(char *restrict s1,
const char *restrict s2, size_t n);
char					*ft_strstr(const char *haystack,
const char *needle);
char					*ft_strnstr(const char *haystack,
const char *needle, size_t len);
char					*ft_strchr(const char *s, int c);
char					*strnstr(const char *haystack,
const char *needle, size_t len);
int						ft_strcmp(const char *s1,
const char *s2);
int						ft_strncmp(const char *s1,
const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isalnum(int c);
int						ft_isdigit(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_converter(unsigned int num, int base);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					**ft_strsplit(char const *s, char c);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
	char (*f)(unsigned int, char));
char					*ft_strtrim(char const *s);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1,
	char const *s2, size_t n);
char					*ft_strndup(const char *s1, size_t sz);
char					*ft_strsub(char const *s,
	unsigned int start, size_t len);
char					*ft_strrchr(const char *s, int c);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
size_t					ft_strlcat(char *restrict dst,
const char *restrict src, size_t dstsize);
void					ft_putnbr(int n);
int						get_next_line(const int fd, char **line);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*ft_itoa(int n);
char					*ft_stupd(char const *s1, char const *s2);
int						ft_sqrt(int n);
int						ft_is_pos(int a);
long					ft_sum(int a, int b);
long					ft_subtr(int a, int b);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
	void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
