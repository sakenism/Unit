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

#include "ft_printf.h"
#include <stdio.h>

int			ushinshi_check(char **ind, t_flags *t, int ker1, int ker2)
{
	double		db;
	void		*p;

	if (**ind == 'f')
	{
		db = va_arg(*get_arg(), double);
		plusf(db, t->znak);
		checkprobel(t, (long long)(db), &ker1);
		ft_putfloat(ker1, t->tochka ? ker2 : 6, db, t);
		if (!ker2 && t->hash)
			ft_putchar('.');
		return (1);
	}
	if (**ind != 'p')
		return (0);
	p = va_arg(*get_arg(), void*);
	if (!t->minus && ker1 > (max(ker2 + t->znak, ft_cnt_memory(p)))
	&& !t->nol && t->cha == ' ')
		pr_pre(ker1, (max(ker2 + t->znak, ft_cnt_memory(p))), ' ');
	ft_print_memory(p, ker1, ker2);
	if ((t->cha == '0' || t->minus) &&
	ker1 > (max(ker2 + t->znak, ft_cnt_memory(p))))
		pr_pre(ker1, (max(ker2 + t->znak, ft_cnt_memory(p))), t->cha);
	return (1);
}

int			third_check(char **ind, t_flags *t, int ker1, int ker2)
{
	char		*s;
	int			i;

	if (**ind == 's')
	{
		s = va_arg(*get_arg(), char *);
		if (!s)
			ft_putstr("(null)");
		if (!s)
			return (1);
		ft_putnstr(s, ker1, ker2, t);
		return (1);
	}
	else if (**ind == 'c')
	{
		if (!t->minus)
			pr_pre(ker1, 1, t->cha);
		i = va_arg(*get_arg(), int);
		ft_putchar(i);
		if (t->minus)
			pr_pre(ker1, 1, t->cha);
		return (1);
	}
	return (0);
}

int			tortinshi_check(char **ind, t_flags *t, int ker1, int ker2)
{
	int			sz;
	signed char	sch;

	if (**ind == 'h' && *(*ind + 1) == 'h' && (*(*ind + 2) == 'd'
	|| *(*ind + 2) == 'i'))
	{
		*ind += 2;
		sch = va_arg(*get_arg(), int);
		sz = helper(t, &ker1, &ker2, sch);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		plusd((long long)sch, t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - minisz(sch));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !sch))
			ft_putll(sch);
		if (t->minus && ker1 > (max(ker2 + t->znak, sz)))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		return (1);
	}
	return (0);
}

int			fourth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	short		sh;
	int			sz;

	if (**ind == 'h' && (*(*ind + 1) == 'd' || *(*ind + 1) == 'i'))
	{
		*ind += 1;
		sh = va_arg(*get_arg(), long long);
		sz = helper(t, &ker1, &ker2, sh);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		plusd((long long)sh, t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - minisz(sh));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !sh))
			ft_putll(sh);
		if (t->minus && ker1 > (max(ker2 + t->znak, sz)))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		return (1);
	}
	return (0);
}
