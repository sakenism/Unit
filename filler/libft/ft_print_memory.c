/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:29:28 by samukano          #+#    #+#             */
/*   Updated: 2018/12/01 22:29:28 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "../ft_printf.h"

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

int		ft_cnt_memory(void *p0)
{
	int			i;
	int			ok;
	int			cnt;
	uintptr_t	p;

	p = (uintptr_t)p0;
	cnt = 2;
	ok = 0;
	i = (sizeof(p) << 3) - 4;
	while (i >= 0)
	{
		if (hex_digit((p >> i) & 0xf) != '0')
			ok = 1;
		if (ok)
			cnt++;
		i -= 4;
	}
	if (!ok)
		cnt++;
	return (cnt);
}

void	ft_print_memory(void *p0, int ker1, int ker2)
{
	int			i;
	int			ok;
	int			cnt;
	uintptr_t	p;

	p = (uintptr_t)p0;
	cnt = get_cnt();
	ok = 0;
	ft_putchar('0');
	ft_putchar('x');
	if (!(!ker1 && !ker2 && !p))
	{
		i = (sizeof(p) << 3) - 4;
		while (i >= 0)
		{
			if (hex_digit((p >> i) & 0xf) != '0')
				ok = 1;
			if (ok)
				ft_putchar(hex_digit((p >> i) & 0xf));
			i -= 4;
		}
		if (!ok)
			ft_putchar('0');
	}
}
