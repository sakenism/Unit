/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 01:02:42 by samukano          #+#    #+#             */
/*   Updated: 2018/12/07 01:02:43 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			twentyfourth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	int		i;

	ker2--;
	while (**ind != '\0')
	{
		if (**ind == '%')
		{
			i = 0;
			if (!t->minus)
				while (i++ < ker1 - 1)
					ft_putchar(t->cha);
			ft_putchar('%');
			if (t->minus)
				while (i++ < ker1 - 1)
					ft_putchar(t->cha);
			break ;
		}
		(*ind)++;
	}
	if (**ind == '\0')
		return (-1);
	return (0);
}
