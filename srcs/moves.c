/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:47:14 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/22 22:03:46 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_image_data *param, t_key_events events, int *count, int *steps)
{
	char	*a;

	events.p2.i = events.p1.i;
	events.p2.j = events.p1.j - 1;
	if (moves(param, events, count, steps))
		return (1);
	display_image(param, "textures/wall_5.xpm", 0, 0);
	printf("%d\n", ++(*steps));
	a = ft_itoa(*steps);
	mlx_string_put(param->mlx, param->mlx_win, 25, 25, 0x0FAE1, a);
	free(a);
	return (0);
}

int	move_up(t_image_data *param, t_key_events events, int *count, int *steps)
{
	char	*a;

	events.p2.i = events.p1.i - 1;
	events.p2.j = events.p1.j;
	if (moves(param, events, count, steps))
		return (1);
	display_image(param, "textures/wall_5.xpm", 0, 0);
	printf("%d\n", ++(*steps));
	a = ft_itoa(*steps);
	mlx_string_put(param->mlx, param->mlx_win, 25, 25, 0x0FAE1, a);
	free(a);
	return (0);
}

int	move_right(t_image_data *param, t_key_events events, int *count, int *steps)
{
	char	*a;

	events.p2.i = events.p1.i;
	events.p2.j = events.p1.j + 1;
	if (moves(param, events, count, steps))
		return (1);
	display_image(param, "textures/wall_5.xpm", 0, 0);
	printf("%d\n", ++(*steps));
	a = ft_itoa(*steps);
	mlx_string_put(param->mlx, param->mlx_win, 25, 25, 0x0FAE1, a);
	free(a);
	return (0);
}

int	move_down(t_image_data *param, t_key_events events, int *count, int *steps)
{
	char	*a;

	events.p2.i = events.p1.i + 1;
	events.p2.j = events.p1.j;
	if (moves(param, events, count, steps))
		return (1);
	display_image(param, "textures/wall_5.xpm", 0, 0);
	printf("%d\n", ++(*steps));
	a = ft_itoa(*steps);
	mlx_string_put(param->mlx, param->mlx_win, 25, 25, 0x0FAE1, a);
	free(a);
	return (0);
}
