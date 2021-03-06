/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 00:09:02 by samukano          #+#    #+#             */
/*   Updated: 2018/11/11 00:09:02 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (*(s + i))
	{
		ft_putchar(*(s + i));
		i++;
	}
	write(1, "\n", 1);
}
