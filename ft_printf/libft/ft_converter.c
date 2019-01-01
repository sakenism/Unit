/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conerter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:07:58 by samukano          #+#    #+#             */
/*   Updated: 2018/11/30 14:07:58 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_converter(unsigned int num, int base)
{
	char		r[22];
	static char	buffer[100];
	int			i;
	char		*ptr;

	ptr = &buffer[99];
	*ptr = '\0';
	i = 0;
	while (++i < 11)
		r[i - 1] = i - 1 + '0';
	if (base > 0)
		while (++i < 18)
			r[i - 2] = i - 12 + 'A';
	else
		while (++i < 18)
			r[i - 2] = i - 12 + 'a';
	if (base < 0)
		base = -base;
	while (1)
	{
		*--ptr = r[num % base];
		if ((num = num / base) == 0)
			break ;
	}
	return (ptr);
}

char	*ft_converterll(unsigned long long num, int base)
{
	char		r[22];
	static char	buffer[100];
	int			i;
	char		*ptr;

	ptr = &buffer[99];
	*ptr = '\0';
	i = 0;
	while (++i < 11)
		r[i - 1] = i - 1 + '0';
	if (base > 0)
		while (++i < 18)
			r[i - 2] = i - 12 + 'A';
	else
		while (++i < 18)
			r[i - 2] = i - 12 + 'a';
	if (base < 0)
		base = -base;
	while (1)
	{
		*--ptr = r[num % base];
		if ((num = num / base) == 0)
			break ;
	}
	return (ptr);
}

char	*ft_converterhh(unsigned char num, int base)
{
	char		r[22];
	static char	buffer[100];
	int			i;
	char		*ptr;

	ptr = &buffer[99];
	*ptr = '\0';
	i = 0;
	while (++i < 11)
		r[i - 1] = i - 1 + '0';
	if (base > 0)
		while (++i < 18)
			r[i - 2] = i - 12 + 'A';
	else
		while (++i < 18)
			r[i - 2] = i - 12 + 'a';
	if (base < 0)
		base = -base;
	while (1)
	{
		*--ptr = r[num % base];
		if ((num = num / base) == 0)
			break ;
	}
	return (ptr);
}

char	*ft_converterh(unsigned short num, int base)
{
	char		r[22];
	static char	buffer[100];
	int			i;
	char		*ptr;

	ptr = &buffer[99];
	*ptr = '\0';
	i = 0;
	while (++i < 11)
		r[i - 1] = i - 1 + '0';
	if (base > 0)
		while (++i < 18)
			r[i - 2] = i - 12 + 'A';
	else
		while (++i < 18)
			r[i - 2] = i - 12 + 'a';
	if (base < 0)
		base = -base;
	while (1)
	{
		*--ptr = r[num % base];
		if ((num = num / base) == 0)
			break ;
	}
	return (ptr);
}

char	*ft_converterl(unsigned long num, int base)
{
	char		r[22];
	static char	buffer[100];
	int			i;
	char		*ptr;

	ptr = &buffer[99];
	*ptr = '\0';
	i = 0;
	while (++i < 11)
		r[i - 1] = i - 1 + '0';
	if (base > 0)
		while (++i < 18)
			r[i - 2] = i - 12 + 'A';
	else
		while (++i < 18)
			r[i - 2] = i - 12 + 'a';
	if (base < 0)
		base = -base;
	while (1)
	{
		*--ptr = r[num % base];
		if ((num = num / base) == 0)
			break ;
	}
	return (ptr);
}
