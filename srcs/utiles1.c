/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:09:01 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/22 21:39:51 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_2d(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	if_exist(char **a, char c)
{
	int	i;
	int	j;

	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_duplicate(char **a, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	else
		return (1);
}

t_pos	get_position(char **map, char m)
{
	t_pos	p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	p.i = 0;
	p.j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == m)
			{
				p.i = i;
				p.j = j;
				return (p);
			}
			j++;
		}
		i++;
	}
	return (p);
}

int	count_collec(char **a)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
