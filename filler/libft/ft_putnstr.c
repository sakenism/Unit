/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:51:07 by samukano          #+#    #+#             */
/*   Updated: 2018/12/02 21:51:08 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "../ft_printf.h"

void	ft_putnstr(char const *s, int ker1, int ker2, t_flags *t)
{
	int	i;

	i = 0;
	ker2 = (ker2 > (int)(ft_strlen(s)) ? (int)ft_strlen(s) : ker2);
	if (!t->tochka)
		ker2 = (int)ft_strlen(s);
	if (!s)
	{
		pr_pre(ker1, ker2, ' ');
		return ;
	}
	if (!t->minus && ker1 > ker2)
		pr_pre(ker1, ker2, ' ');
	i = 0;
	while (*(s + i) && ker2 - i > 0)
	{
		ft_putchar(*(s + i));
		i++;
	}
	if (t->minus && ker1 > ker2)
		pr_pre(ker1, ker2, ' ');
}
