/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:12:42 by samukano          #+#    #+#             */
/*   Updated: 2018/12/06 19:12:43 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		helper(t_flags *t, int *ker1, int *ker2, long long n)
{
	int		sz;

	if (t->tochka)
		t->cha = ' ';
	if (t->tochka)
		t->nol = 0;
	sz = minisz(n) + t->znak;
	if (n < 0 && t->tochka && *ker2 > minisz(n))
		*ker1 = *ker1 - 1 + (n < 0 && t->znak);
	if (!t->znak)
		sz = n < 0 ? sz + 1 : sz;
	if (!t->tochka)
		*ker2 = sz - 1;
	checkprobel(t, n, ker1);
	return (sz);
}

int		zeroth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	long				l;
	int					sz;

	if (**ind == 'l' && (*((*ind + 1)) == 'd' || *((*ind + 1)) == 'i'))
	{
		l = va_arg(*get_arg(), long);
		*ind += 1;
		sz = helper(t, &ker1, &ker2, l);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		plusd((long long)l, t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - minisz(l));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !l))
			ft_putll(l);
		if (t->minus && ker1 > (max(ker2 + t->znak, sz)))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		return (1);
	}
	return (0);
}

int		birinshi_check(char **ind, t_flags *t, int ker1, int ker2)
{
	long double			ldb;
	double				db;

	if (**ind == 'l' && *(*ind + 1) == 'f')
	{
		db = va_arg(*get_arg(), double);
		plusf(db, t->znak);
		checkprobel(t, (long long)(db), &ker1);
		ft_putfloat(ker1, t->tochka ? ker2 : 6, db, t);
		(*ind)++;
		return (1);
	}
	else if (**ind == 'L' && *(*ind + 1) == 'f')
	{
		ldb = va_arg(*get_arg(), long double);
		plusf(ldb, t->znak);
		checkprobel(t, (long long)(ldb), &ker1);
		ft_putfloat(ker1, t->tochka ? ker2 : 6, ldb, t);
		if (!ker2 && t->hash)
			ft_putchar('.');
		(*ind)++;
		return (1);
	}
	return (0);
}

int		first_check(char **ind, t_flags *t, int ker1, int ker2)
{
	long long			ll;
	int					sz;

	if (**ind == 'l' && *(*ind + 1) == 'l' && (*(*ind + 2) == 'd'
	|| *(*ind + 2) == 'i'))
	{
		*ind += 2;
		ll = va_arg(*get_arg(), long long);
		sz = helper(t, &ker1, &ker2, ll);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		plusd(ll, t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - minisz(ll));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !ll))
			ft_putll(ll);
		if (t->minus && ker1 > (max(ker2 + t->znak, sz)))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		return (1);
	}
	return (0);
}

int		ekinshi_check(char **ind, t_flags *t, int ker1, int ker2)
{
	int			i;
	int			sz;

	if (**ind == 'd' || **ind == 'i')
	{
		i = va_arg(*get_arg(), int);
		sz = helper(t, &ker1, &ker2, i);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		plusd((long long)i, t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - minisz(i));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !i))
			ft_putll(i);
		if (t->minus && ker1 > (max(ker2 + t->znak, sz)))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		return (1);
	}
	return (0);
}
