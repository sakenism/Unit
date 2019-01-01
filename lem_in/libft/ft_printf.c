/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:35:51 by samukano          #+#    #+#             */
/*   Updated: 2018/11/30 13:35:51 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			g_cnt = 0;
va_list		*g_arg;

va_list		*get_arg(void)
{
	return (g_arg);
}

int			get_cnt(void)
{
	return (g_cnt);
}

void		cnt_puts(void)
{
	g_cnt++;
}

int			razbei(t_flags *t, char **ind, int *ker1, int *ker2)
{
	clearflags(t);
	while (**ind != '%' && **ind != '\0')
	{
		ft_putchar(**ind);
		(*ind)++;
	}
	if ((**ind) == '\0')
		return (-1);
	(*ind)++;
	while (beginning(ind, t))
		(*ind)++;
	*ker1 = ft_atoi(*ind);
	while (**ind >= '0' && **ind <= '9')
		(*ind)++;
	if (**ind == '.')
		t->tochka = 1;
	*ker2 = t->tochka ? ft_atoi(*ind) : 0;
	return (0);
}

int			ft_printf(char *ind, ...)
{
	int					ker1;
	int					ker2;
	va_list				arg;
	t_flags				t;

	va_start(arg, ind);
	g_arg = &arg;
	ker1 = 0;
	ker2 = 6;
	while (*ind != '\0')
	{
		if (razbei(&t, &ind, &ker1, &ker2) == -1)
			break ;
		while (*ind >= '0' && *ind <= '9')
			ind++;
		if (kereksan(&t, &ind, &ker1, &ker2) == -1)
			break ;
		if (*ind == '\0')
			break ;
		zapusk(&ind, &t, ker1, ker2);
		ind++;
	}
	va_end(arg);
	return (g_cnt);
}
