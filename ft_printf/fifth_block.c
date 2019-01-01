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

void		helperx(t_flags *t, int *ker1, int *ker2, unsigned long long n)
{
	if (!t->tochka)
		*ker2 = (int)ft_strlen(ft_converterll(n, -16));
	if (t->tochka)
		t->cha = ' ';
	if (n != 0 && t->hash && t->cha == '0')
		ft_putstr("0x");
	(*ker1) += 2;
	(*ker1) -= 1;
	(*ker1) -= 1;
}

void		helperxx(t_flags *t, int *ker1, int *ker2, unsigned long long n)
{
	if (!t->tochka)
		*ker2 = (int)ft_strlen(ft_converterll(n, 16));
	if (t->tochka)
		t->cha = ' ';
	if (n != 0 && t->hash && t->cha == '0')
		ft_putstr("0X");
	(*ker1) += 2;
	(*ker1) -= 1;
	(*ker1) -= 1;
}

int			ninth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long		ul;

	if (**ind == 'l' && *(*ind + 1) == 'o')
	{
		ul = va_arg(*get_arg(), unsigned long);
		helpero(t, &ker1, &ker2, ul);
		if (ul != 0 && t->hash)
			ft_putchar('0');
		if (t->tochka)
			pr_zero(ker2 - (int)ft_strlen(ft_converterl(ul, 8)));
		if (ul != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converterl(ul, 8));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, (int)ft_strlen(ft_converterl(ul, 8))))
			pr_pre(ker1 - t->hash, max(ker2,
			(int)ft_strlen(ft_converterl(ul, 8))), t->cha);
		(*ind) += 1;
		return (1);
	}
	return (0);
}

int			tenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned short			ush;
	int						sz;

	if (**ind == 'h' && *(*ind + 1) == 'u')
	{
		*ind += 1;
		ush = va_arg(*get_arg(), unsigned int);
		sz = helperu(t, &ker1, &ker2, ush);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(ush));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !ush))
			ft_putull(ush);
		if (t->minus && ker1 > (max(ker2 + t->znak, sz)))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		return (1);
	}
	return (0);
}

int			segizinshi_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long		ul;
	int					sz;

	if (**ind == 'l' && *(*ind + 1) == 'u')
	{
		ul = va_arg(*get_arg(), unsigned long);
		*ind += 1;
		sz = helperu(t, &ker1, &ker2, ul);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(ul));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !ul))
			ft_putull(ul);
		if (t->minus && ker1 > (max(ker2 + t->znak, sz)))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		return (1);
	}
	return (0);
}
