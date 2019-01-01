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

void		helpero(t_flags *t, int *ker1, int *ker2, unsigned long long n)
{
	if (!t->tochka)
		*ker2 = ft_strlen(ft_converterll(n, 8) + t->hash);
	if (t->tochka)
		t->cha = ' ';
	if (!t->minus && *ker1 > max(*ker2, ft_strlen(ft_converterll(n, 8))))
		pr_pre(*ker1 - t->hash, max(*ker2,
		ft_strlen(ft_converterll(n, 8))), t->cha);
}

int			fifth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned int		ui;

	if (**ind == 'o')
	{
		ui = va_arg(*get_arg(), unsigned int);
		helpero(t, &ker1, &ker2, ui);
		if (ui != 0 && t->hash)
			ft_putchar('0');
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converter(ui, 8)));
		if (ui != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converter(ui, 8));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converter(ui, 8))))
			pr_pre(ker1 - t->hash, max(ker2,
			ft_strlen(ft_converter(ui, 8))), t->cha);
		return (1);
	}
	return (0);
}

int			sixth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned char		uc;

	if (**ind == 'h' && *(*ind + 1) == 'h' && *(*ind + 2) == 'o')
	{
		uc = va_arg(*get_arg(), int);
		helpero(t, &ker1, &ker2, uc);
		if (uc != 0 && t->hash)
			ft_putchar('0');
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterhh(uc, 8)));
		if (uc != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converterhh(uc, 8));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterhh(uc, 8))))
			pr_pre(ker1 - t->hash, max(ker2,
			ft_strlen(ft_converterhh(uc, 8))), t->cha);
		(*ind) += 2;
		return (1);
	}
	return (0);
}

int			seventh_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned short	ush;

	if (**ind == 'h' && *(*ind + 1) == 'o')
	{
		ush = va_arg(*get_arg(), unsigned int);
		helpero(t, &ker1, &ker2, ush);
		if (ush != 0 && t->hash)
			ft_putchar('0');
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterh(ush, 8)));
		if (ush != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converterh(ush, 8));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterh(ush, 8))))
			pr_pre(ker1 - t->hash, max(ker2,
			ft_strlen(ft_converterh(ush, 8))), t->cha);
		(*ind) += 1;
		return (1);
	}
	return (0);
}

int			eighth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long long			ull;

	if (**ind == 'l' && *(*ind + 1) == 'l' && *(*ind + 2) == 'o')
	{
		ull = va_arg(*get_arg(), unsigned long long);
		helpero(t, &ker1, &ker2, ull);
		if (ull != 0 && t->hash)
			ft_putchar('0');
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterll(ull, 8)));
		if (ull != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converterll(ull, 8));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterll(ull, 8))))
			pr_pre(ker1 - t->hash, max(ker2,
			ft_strlen(ft_converterll(ull, 8))), t->cha);
		(*ind) += 2;
		return (1);
	}
	return (0);
}
