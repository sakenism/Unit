/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meloch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 00:56:11 by samukano          #+#    #+#             */
/*   Updated: 2018/12/07 00:56:12 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	max(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}

void		plusf(long double a, int znak)
{
	if (a >= 0.0 && znak)
		ft_putchar('+');
}

void		pr_pre(int n, int m, char c)
{
	while (n > m)
	{
		ft_putchar(c);
		n--;
	}
}

void		pr_zero(int n)
{
	while (n > 0)
	{
		ft_putchar('0');
		n--;
	}
}

void		checkprobel(t_flags *t, long long n, int *ker1)
{
	if (!t->znak && n >= 0 && t->probel)
	{
		ft_putchar(' ');
		*ker1 -= 1;
	}
}
