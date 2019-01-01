/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:46:21 by samukano          #+#    #+#             */
/*   Updated: 2018/11/15 12:46:21 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strndup(const char *s1, size_t sz)
{
	size_t	n;
	char	*ans;

	if (!s1)
		return (NULL);
	ans = (char*)malloc((sz + 1));
	if (ans != NULL)
	{
		n = 0;
		while (n < sz)
		{
			*(ans + n) = *(s1 + n);
			n++;
		}
		*(ans + n) = '\0';
	}
	return (ans);
}
