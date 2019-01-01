/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 23:38:05 by samukano          #+#    #+#             */
/*   Updated: 2018/12/06 23:38:06 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		helperb(t_flags *t, int *ker1, int *ker2, unsigned long long n)
{
	if (!t->tochka)
		*ker2 = (int)ft_strlen(ft_converterll(n, 2));
	if (t->tochka)
		t->cha = ' ';
	if (n != 0 && t->hash && t->cha == '0')
		ft_putstr("0x");
	(*ker1) += 2;
	(*ker1) -= 1;
	(*ker1) -= 1;
}

int			beginning(char **ind, t_flags *t)
{
	if (**ind == ' ')
	{
		t->probel = 1;
		return (1);
	}
	if (**ind == '+')
	{
		t->znak = 1;
		return (1);
	}
	if (**ind == '-')
	{
		t->nol = 0;
		t->minus = 1;
		t->cha = ' ';
		return (1);
	}
	return (beginning_cont(ind, t));
}

int			beginning_cont(char **ind, t_flags *t)
{
	if (**ind == '#')
	{
		t->hash = 1;
		return (1);
	}
	if (**ind == '0' && !t->minus)
	{
		t->nol = 1;
		t->cha = '0';
		return (1);
	}
	if (**ind == '.')
		t->tochka = 1;
	return (0);
}

int			kereksan(t_flags *t, char **ind, int *ker1, int *ker2)
{
	if (**ind >= '0' && **ind <= '9')
	{
		if (**ind == '0')
		{
			t->cha = '0';
			t->nol = 1;
		}
		*ker1 = ft_atoi(*ind);
		while (**ind >= '0' && **ind <= '9')
			(*ind)++;
	}
	if (**ind == '\0')
		return (-1);
	if (**ind == '.')
	{
		t->tochka = 1;
		(*ind)++;
		*ker2 = ft_atoi(*ind);
		while (**ind >= '0' && **ind <= '9')
			(*ind)++;
	}
	return (0);
}

void		plusd(long long a, int znak)
{
	if (a == INTMAX_MIN)
		return ;
	if (a >= 0 && znak)
	{
		ft_putchar('+');
	}
	if (a < 0)
	{
		ft_putchar('-');
	}
}
