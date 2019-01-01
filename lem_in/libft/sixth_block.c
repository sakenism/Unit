/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixth_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 23:18:16 by samukano          #+#    #+#             */
/*   Updated: 2018/12/06 23:18:17 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			eleventh_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned char		uc;

	if (**ind == 'h' && *(*ind + 1) == 'h' && *(*ind + 2) == 'x')
	{
		uc = va_arg(*get_arg(), int);
		helperx(t, &ker1, &ker2, uc);
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterhh(uc, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2,
			ft_strlen(ft_converterhh(uc, -16))), t->cha);
		if (uc != 0 && t->hash && t->cha == ' ')
			ft_putstr("0x");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterhh(uc, -16)));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !uc))
			ft_putstr(ft_converterhh(uc, -16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterhh(uc, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2,
			ft_strlen(ft_converterhh(uc, -16))), t->cha);
		(*ind) += 2;
		return (1);
	}
	return (0);
}

int			twelfth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long long		ull;

	if (**ind == 'l' && *(*ind + 1) == 'l' && *(*ind + 2) == 'x')
	{
		ull = va_arg(*get_arg(), unsigned long long);
		helperx(t, &ker1, &ker2, ull);
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterll(ull, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2,
			ft_strlen(ft_converterll(ull, -16))), t->cha);
		if (ull != 0 && t->hash && t->cha == ' ')
			ft_putstr("0x");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterll(ull, -16)));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !ull))
			ft_putstr(ft_converterll(ull, -16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterll(ull, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2,
			ft_strlen(ft_converterll(ull, -16))), t->cha);
		(*ind) += 2;
		return (1);
	}
	return (0);
}

int			thirteenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned int		ui;

	if (**ind == 'x')
	{
		ui = va_arg(*get_arg(), unsigned int);
		helperx(t, &ker1, &ker2, ui);
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converter(ui, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2,
			ft_strlen(ft_converter(ui, -16))), t->cha);
		if (ui != 0 && t->hash && t->cha == ' ')
			ft_putstr("0x");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converter(ui, -16)));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !ui))
			ft_putstr(ft_converter(ui, -16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converter(ui, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2,
			ft_strlen(ft_converter(ui, -16))), t->cha);
		return (1);
	}
	return (0);
}

int			fourteenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned short		ush;

	if (**ind == 'h' && *(*ind + 1) == 'x')
	{
		ush = va_arg(*get_arg(), int);
		helperx(t, &ker1, &ker2, ush);
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterh(ush, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2,
			ft_strlen(ft_converterh(ush, -16))), t->cha);
		if (ush != 0 && t->hash && t->cha == ' ')
			ft_putstr("0x");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterh(ush, -16)));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !ush))
			ft_putstr(ft_converterh(ush, -16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterh(ush, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2,
			ft_strlen(ft_converterh(ush, -16))), t->cha);
		(*ind) += 1;
		return (1);
	}
	return (0);
}

int			fifteenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long		ul;

	if (**ind == 'l' && *(*ind + 1) == 'x')
	{
		ul = va_arg(*get_arg(), unsigned long);
		helperx(t, &ker1, &ker2, ul);
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterl(ul, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2,
			ft_strlen(ft_converterl(ul, -16))), t->cha);
		if (ul != 0 && t->hash && t->cha == ' ')
			ft_putstr("0x");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterl(ul, -16)));
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if (!(!ker1 && t->tochka && !ker2 && !ul))
			ft_putstr(ft_converterl(ul, -16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterl(ul, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2,
			ft_strlen(ft_converterl(ul, -16))), t->cha);
		(*ind) += 1;
		return (1);
	}
	return (0);
}
