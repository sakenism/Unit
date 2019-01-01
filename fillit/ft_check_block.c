/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:05:44 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/29 18:10:38 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_symbols(char *str)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '#' && str[i] != '\n' && str[i] != '.')
			return (1);
		if (str[i] == '#')
			j++;
		if (str[i] == '.')
			k++;
		i++;
	}
	if (j != 4 || k != 12)
		return (1);
	return (0);
}

int		ft_check_endl(char *str)
{
	int	i;
	int	len;
	int	count;

	len = ft_strlen(str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	if (count == 4)
	{
		if (len == 20 && str[4] == '\n' && str[9] == '\n' &&
		str[14] == '\n' && str[19] == '\n')
			return (0);
	}
	return (1);
}

int		ft_check_contact(char *s)
{
	int		i;
	int		count;
	char	**str;
	int		j;

	i = -1;
	count = 0;
	str = ft_strsplit(s, '\n');
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (str[i][j] == '#')
			{
				count = j <= 3 && str[i][j + 1] == '#' ? count + 1 : count;
				count = j >= 1 && str[i][j - 1] == '#' ? count + 1 : count;
				count = i < 3 && str[i + 1][j] == '#' ? count + 1 : count;
				count = i >= 1 && str[i - 1][j] == '#' ? count + 1 : count;
			}
	}
	i = -1;
	fresh(str, 111111);
	return (count == 8 || count == 6);
}

int		help(t_tmp *t)
{
	while (++(t->i) < 4)
	{
		ft_bzero(t->tmp, 5);
		if (read(t->fd, t->tmp, 5) <= 0)
			break ;
		t->str = ft_strcat(t->str, t->tmp);
	}
	if (ft_main_check(t->str) == -2)
		return (-2);
	t->big = ft_strcat(t->big, t->str);
	(t->cnt)++;
	if (read(t->fd, &(t->c), 1) <= 0)
		return (-1);
	else if (t->c != '\n')
		return (ft_error());
	return (ft_main_check(t->str));
}

int		main(int argc, char **argv)
{
	t_tmp	t;

	t.big = (char*)malloc(111111);
	t.str = (char*)malloc(111111);
	t.tmp = (char*)malloc(111111);
	t.cnt = 0;
	t.c = '\n';
	if (argc != 2 || (t.fd = open(argv[1], O_RDONLY)) < 0)
		return (die(t.fd));
	while (t.c == '\n')
	{
		ft_bzero(t.str, 16);
		t.i = -1;
		if ((t.tint = help(&t)) == -1)
			break ;
		if (t.tint == -2)
			close(t.fd);
		if (t.tint == -2)
			return (0);
	}
	if (t.cnt < 1 || t.cnt > 26)
		return (ft_error0());
	lst(t);
	return (0);
}
