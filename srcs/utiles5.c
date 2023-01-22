/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:33:56 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/22 21:29:36 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clear(int key, t_image_data *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx, param->mlx_win);
		exit(0);
	}
	return (0);
}

int	exit_win(t_image_data *param)
{
	mlx_destroy_window(param->mlx, param->mlx_win);
	exit(0);
	return (0);
}

void	swap_elm(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	free_2d_table(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}
