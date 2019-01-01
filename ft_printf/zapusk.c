/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zapusk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:11:31 by samukano          #+#    #+#             */
/*   Updated: 2018/12/06 19:11:33 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		zapusk4(char **ind, t_flags *t, int ker1, int ker2)
{
	int	sum;

	sum = 0;
	sum += zhetinshi_check(ind, t, ker1, ker2);
	if (!sum)
		sum += segizinshi_check(ind, t, ker1, ker2);
	if (!sum)
		sum += togizinshi_check(ind, t, ker1, ker2);
	if (!sum)
		sum += oninshi_check(ind, t, ker1, ker2);
	if (!sum)
		sum += zeroth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += twentyfourth_check(ind, t, ker1, ker2);
}

void		zapusk3(char **ind, t_flags *t, int ker1, int ker2)
{
	int	sum;

	sum = 0;
	sum += twentysecond_check(ind, t, ker1, ker2);
	if (!sum)
		sum += twentythird_check(ind, t, ker1, ker2);
	if (!sum)
		sum += birinshi_check(ind, t, ker1, ker2);
	if (!sum)
		sum += ekinshi_check(ind, t, ker1, ker2);
	if (!sum)
		sum += ushinshi_check(ind, t, ker1, ker2);
	if (!sum)
		sum += tortinshi_check(ind, t, ker1, ker2);
	if (!sum)
		sum += besinshi_check(ind, t, ker1, ker2);
	if (!sum)
		sum += altinshi_check(ind, t, ker1, ker2);
	if (!sum)
		sum += second_check(ind, t, ker1, ker2);
	if (!sum)
		zapusk4(ind, t, ker1, ker2);
}

void		zapusk2(char **ind, t_flags *t, int ker1, int ker2)
{
	int	sum;

	sum = 0;
	if (!sum)
		sum += twelfth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += thirteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += fourteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += fifteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += sixteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += seventeenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += eightteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += nineteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += twentith_check(ind, t, ker1, ker2);
	if (!sum)
		sum += twentyfirst_check(ind, t, ker1, ker2);
	if (!sum)
		zapusk3(ind, t, ker1, ker2);
}

void		zapusk(char **ind, t_flags *t, int ker1, int ker2)
{
	int	sum;

	sum = 0;
	sum += first_check(ind, t, ker1, ker2);
	if (!sum)
		sum += third_check(ind, t, ker1, ker2);
	if (!sum)
		sum += fourth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += fifth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += sixth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += seventh_check(ind, t, ker1, ker2);
	if (!sum)
		sum += eighth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += ninth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += tenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += eleventh_check(ind, t, ker1, ker2);
	if (!sum)
		zapusk2(ind, t, ker1, ker2);
}
