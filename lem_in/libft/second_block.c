/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:12:42 by samukano          #+#    #+#             */
/*   Updated: 2018/12/06 20:41:01 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			helperu(t_flags *t, int *ker1, int *ker2, unsigned long long n)
{
	int	sz;

	if (t->tochka)
	{
		t->cha = ' ';
		t->nol = 0;
	}
	sz = uminisz(n) + t->znak;
	if (!t->tochka)
		*ker2 = sz - 1;
	if (!t->minus && *ker1 > (max(*ker2 + t->znak, sz)) && !t->nol)
		pr_pre(*ker1, (max(*ker2 + t->znak, sz)), ' ');
	return (sz);
}

int			second_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned int		ui;
	int					sz;

	if (**ind == 'u')
	{
		ui = va_arg(*get_arg(), unsigned int);
		sz = helperu(t, &ker1, &ker2, ui);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(ui));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !ui))
			ft_putull(ui);
		if (t->minus && ker1 > (max(ker2 + t->znak, sz)))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		return (1);
	}
	return (0);
}

int			besinshi_check(char **ind, t_flags *t, int ker1, int ker2)
{
	int						sz;
	unsigned char			uc;

	if (**ind == 'h' && *(*ind + 1) == 'h' && *(*ind + 2) == 'u')
	{
		*ind += 2;
		uc = va_arg(*get_arg(), int);
		sz = helperu(t, &ker1, &ker2, uc);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(uc));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !uc))
			ft_putull(uc);
		if (t->minus && ker1 > (max(ker2 + t->znak, sz)))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		return (1);
	}
	return (0);
}

int			altinshi_check(char **ind, t_flags *t, int ker1, int ker2)
{
	int						sz;
	unsigned long long		ull;

	if (**ind == 'l' && *(*ind + 1) == 'l' && *(*ind + 2) == 'u')
	{
		*ind += 2;
		ull = va_arg(*get_arg(), unsigned long long);
		sz = helperu(t, &ker1, &ker2, ull);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(ull));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !ull))
			ft_putull(ull);
		if (t->minus && ker1 > (max(ker2 + t->znak, sz)))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		return (1);
	}
	return (0);
}

int			zhetinshi_check(char **ind, t_flags *t, int ker1, int ker2)
{
	int				sz;
	unsigned long	ul;

	if (**ind == 'l' && *(*ind + 1) == 'u')
	{
		*ind += 1;
		ul = va_arg(*get_arg(), unsigned long);
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
