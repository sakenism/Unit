/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stupd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:50:37 by samukano          #+#    #+#             */
/*   Updated: 2018/11/17 15:50:37 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_stupd(char const *s1, char const *s2)
{
	char	*t;

	if (!s1 || !s2)
		return (NULL);
	t = ft_strjoin(s1, s2);
	ft_strdel((char**)(&s1));
	return (t);
}
