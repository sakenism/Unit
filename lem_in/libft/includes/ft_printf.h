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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

# define UI unsigned int

int					ft_printf(char *str, ...);
void				ft_putfloat(int ker1, int n, double f, t_flags *t);
int					minisz(long long n);
void				cnt_puts(void);
int					uminisz(unsigned long long n);
void				cnt_dec(void);
long long			max(long long a, long long b);
void				zapusk(char **ind, t_flags *t, int ker1, int ker2);
void				zapusk2(char **ind, t_flags *t, int ker1, int ker2);
int					twentysecond_check(char **ind,
t_flags *t, int ker1, int ker2);
int					twentyfirst_check(char **ind,
t_flags *t, int ker1, int ker2);
int					twentythird_check(char **ind,
t_flags *t, int ker1, int ker2);
int					togizinshi_check(char **ind,
t_flags *t, int ker1, int ker2);
int					oninshi_check(char **ind,
t_flags *t, int ker1, int ker2);
va_list				*get_arg(void);
int					get_cnt(void);
void				helperx(t_flags *t, int *ker1, int *ker2,
unsigned long long n);
void				zapusk3(char **ind, t_flags *t, int ker1,
int ker2);
void				zapusk4(char **ind, t_flags *t, int ker1,
int ker2);
int					eleventh_check(char **ind, t_flags *t,
int ker1, int ker2);
int					zeroth_check(char **ind, t_flags *t,
int ker1, int ker2);
void				ft_putfloat4(int n, double f,
t_flags *t, t_need *nd);
void				ft_putfloat3(int n, double f,
t_flags *t, t_need *nd);
void				ft_putfloat2(int n, double f,
t_flags *t, t_need *nd);
void				ft_putfloat(int ker1, int n,
double f, t_flags *t);
void				begfloat(t_need *nd, double *f, int ker1, int n);
int					beginning(char **ind, t_flags *t);
int					beginning_cont(char **ind, t_flags *t);
long long			max(long long a, long long b);
void				helperb(t_flags *t, int *ker1, int *ker2,
unsigned long long n);
int					birinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
int					togizinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
void				pr_pre(int n, int m, char c);
void				plusf(long double a, int znak);
int					sixteenth_check(char **ind, t_flags *t,
int ker1, int ker2);
void				helperxx(t_flags *t, int *ker1, int *ker2,
unsigned long long n);
void				pr_zero(int n);
int					nineteenth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					first_check(char **ind, t_flags *t,
int ker1, int ker2);
int					twentyfirst_check(char **ind, t_flags *t,
int ker1, int ker2);
int					twentyfourth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					togizinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
void				helpero(t_flags *t, int *ker1, int *ker2,
unsigned long long n);
void				checkprobel(t_flags *t, long long n,
int *ker1);
int					togizinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
int					fifteenth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					seventeenth_check(char **ind, t_flags *t,
int ker1, int ker2);
void				clearflags(t_flags *t);
int					togizinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
int					twelfth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					kereksan(t_flags *t, char **ind,
int *ker1, int *ker2);
int					helper(t_flags *t, int *ker1, int *ker2,
long long n);
int					twentith_check(char **ind, t_flags *t,
int ker1, int ker2);
int					eightteenth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					ekinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
void				plusd(long long a, int znak);
int					fourteenth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					thirteenth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					ninth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					fifth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					second_check(char **ind, t_flags *t,
int ker1, int ker2);
int					segizinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
int					fourth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					tortinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
int					sixth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					tenth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					eighth_check(char **ind, t_flags *t,
int ker1, int ker2);
int					seventh_check(char **ind, t_flags *t,
int ker1, int ker2);
int					helperu(t_flags *t, int *ker1, int *ker2,
unsigned long long n);
int					besinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
int					ushinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
int					third_check(char **ind, t_flags *t,
int ker1, int ker2);
int					altinshi_check(char **ind, t_flags *t,
int ker1, int ker2);
int					zhetinshi_check(char **ind, t_flags *t,
int ker1, int ker2);

#endif
