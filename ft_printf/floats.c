/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:38:52 by samukano          #+#    #+#             */
/*   Updated: 2018/12/07 18:38:56 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putfloat4(int n, double f, t_flags *t, t_need *nd)
{
	(nd->i) = 0;
	f = 3.1415;
	while (nd->ker1 > n + (nd->dot) +
	minisz((nd->tmp1)) + (nd->i)++ && !t->minus)
		ft_putchar(t->cha);
	ft_putnbr((nd->tmp1));
	if (n > 0 || (nd->dot) == 1)
		ft_putchar('.');
	(nd->i) = 0;
	while ((nd->i) < n)
		ft_putchar((nd->a[(nd->i)++]) + '0');
	(nd->i) = 0;
	while (nd->ker1 > n + (nd->dot)
	+ minisz((nd->tmp1)) + (nd->i)++ && t->minus)
		ft_putchar(t->cha);
}

void		ft_putfloat3(int n, double f, t_flags *t, t_need *nd)
{
	if (nd->a[(nd->i)] == 10)
		nd->a[(nd->i)--] = 0;
	if ((nd->i)++ == -1)
	{
		(nd->tmp1)++;
		while (nd->ker1 > n + (nd->dot) +
		minisz((nd->tmp1)) + (nd->i)++ && !t->minus)
			ft_putchar(t->cha);
		(nd->i)--;
		ft_putnbr((nd->tmp1));
		if (n > 0 || (nd->dot) == 1)
			ft_putchar('.');
		while ((nd->i)++ < n)
			ft_putchar('0');
		return ;
	}
	ft_putfloat4(n, f, t, nd);
}

void		ft_putfloat2(int n, double f, t_flags *t, t_need *nd)
{
	while ((nd->i) < 5000)
		nd->a[(nd->i)++] = 0;
	(nd->i) = 0;
	while (f > 0 && (nd->i) < n + 1)
	{
		nd->digit = (int)(f);
		nd->a[(nd->i)] = nd->digit;
		f -= nd->digit;
		f *= 10.0;
		(nd->i)++;
	}
	if ((nd->i) == n + 1 && nd->a[--(nd->i)] >= 5)
		nd->a[--(nd->i)]++;
	while ((nd->i) >= 1)
	{
		if (nd->a[(nd->i)] == 10)
		{
			nd->a[(nd->i)] = 0;
			nd->a[(nd->i) - 1]++;
		}
		else
			break ;
		(nd->i)--;
	}
	ft_putfloat3(n, f, t, nd);
}
