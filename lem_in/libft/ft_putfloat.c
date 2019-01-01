/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:38:58 by samukano          #+#    #+#             */
/*   Updated: 2018/11/30 14:38:58 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

long long	sz(int n)
{
	int			cnt;
	int			i;
	long long	ans;

	cnt = 0;
	i = 0;
	ans = 1;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	while (i < cnt - 1)
	{
		ans *= 10;
		i++;
	}
	return (ans);
}

int			minisz(long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

int			uminisz(unsigned long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void		begfloat(t_need *nd, double *f, int ker1, int n)
{
	(nd->i) = 0;
	(nd->dot) = n > 0 ? 1 : 0;
	(nd->tmp1) = (int)(*f);
	(nd->i) = 0;
	(nd->ker1) = ker1;
	*f -= (nd->tmp1);
	*f *= 10;
}

void		ft_putfloat(int ker1, int n, double f, t_flags *t)
{
	t_need	nd;

	begfloat(&nd, &f, ker1, n);
	if (!n && t->hash)
	{
		if (!t->minus)
			while ((nd.i) + 1 + minisz((nd.tmp1)) < ker1)
			{
				ft_putchar(t->cha);
				(nd.i)++;
			}
		ft_putnbr(f > 5.0 ? (nd.tmp1) + 1 : (nd.tmp1));
		ft_putchar('.');
		if (t->minus)
			while ((nd.i) + 1 + minisz((nd.tmp1)) < ker1)
			{
				ft_putchar(t->cha);
				(nd.i)++;
			}
		return ;
	}
	(nd.i) = 0;
	ft_putfloat2(n, f, t, &nd);
}
