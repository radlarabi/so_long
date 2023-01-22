/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:30:25 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/22 22:17:16 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_image(t_image_data *param, char *img, int a, int b)
{
	int		i;
	int		j;
	void	*s;

	s = mlx_xpm_file_to_image(param->mlx, img, &i, &j);
	mlx_put_image_to_window(param->mlx, param->mlx_win, s, 50 * b, 50 * a);
}

void	sub_moves(t_image_data *param, t_key_events events, int *count)
{
	if (param->game.map[events.p2.i][events.p2.j] == 'C')
		(*count)++;
	if (*count == param->game.coll)
	{
		display_image(param, "textures/brick_1.xpm",
			get_position(param->game.map, 'E').i,
			get_position(param->game.map, 'E').j);
		display_image(param, "textures/open_door.xpm",
			get_position(param->game.map, 'E').i,
			get_position(param->game.map, 'E').j);
	}
	swap_images(param, events.p1, events.p2);
	swap_elm(&param->game.map[events.p1.i][events.p1.j],
		&param->game.map[events.p2.i][events.p2.j]);
	if (param->game.map[events.p1.i][events.p1.j] == 'C')
		param->game.map[events.p1.i][events.p1.j] = '0';
}

int	moves(t_image_data *param, t_key_events events, int *count, int *steps)
{
	if (param->game.map[events.p2.i][events.p2.j] == 'E'
		&& *count == param->game.coll)
	{
		printf("%d\n", ++(*steps));
		free_2d_table(param->game.map);
		write(1, "You win !!\n", 11);
		exit(0);
	}
	if (param->game.map[events.p2.i][events.p2.j] == 'I')
	{
		printf("%d\n", ++(*steps));
		free_2d_table(param->game.map);
		write(1, "You Lose !!\n", 12);
		exit(0);
	}
	if (param->game.map[events.p2.i][events.p2.j] == '1'
		|| param->game.map[events.p2.i][events.p2.j] == 'E')
		return (1);
	sub_moves(param, events, count);
	return (0);
}
