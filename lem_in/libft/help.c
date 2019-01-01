/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 00:24:00 by samukano          #+#    #+#             */
/*   Updated: 2018/12/07 00:24:01 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		clearflags(t_flags *t)
{
	t->nol = 0;
	t->znak = 0;
	t->probel = 0;
	t->ker1 = 0;
	t->ker2 = 0;
	t->tochka = 0;
	t->cnt = 0;
	t->minus = 0;
	t->cha = ' ';
	t->hash = 0;
	t->sign = 1;
}
