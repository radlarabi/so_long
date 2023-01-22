/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:33:04 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/22 22:16:03 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_images(t_image_data *param, t_pos p1, t_pos p2)
{
	display_image(param, "textures/brick_1.xpm", p1.i, p1.j);
	display_image(param, "textures/brick_1.xpm", p2.i, p2.j);
	if (p1.i == p2.i && p1.j - 1 == p2.j)
		display_image(param, "textures/player1.xpm", p2.i, p2.j);
	else if (p1.i == p2.i && p1.j + 1 == p2.j)
		display_image(param, "textures/player4.xpm", p2.i, p2.j);
	else if (p1.i - 1 == p2.i && p1.j == p2.j)
		display_image(param, "textures/player3.xpm", p2.i, p2.j);
	else if (p1.i + 1 == p2.i && p1.j == p2.j)
		display_image(param, "textures/player2.xpm", p2.i, p2.j);
}

int	press_key(int key, t_image_data *param)
{
	static int		steps;
	static int		count;
	t_pos			p1;
	t_key_events	events;

	events.p1 = get_position(param->game.map, 'P');
	p1 = get_position(param->game.map, 'P');
	if (key == 0 || key == 123)
		move_left(param, events, &count, &steps);
	else if (key == 1 || key == 125)
		move_down(param, events, &count, &steps);
	else if (key == 2 || key == 124)
		move_right(param, events, &count, &steps);
	else if (key == 13 || key == 126)
		move_up(param, events, &count, &steps);
	else if (key == 53)
		exit(0);
	return (1);
}

void	display_animation(t_image_data *param, int a, int b)
{
	static int	k;
	static int	p;

	while (param->game.map[++a])
	{
		b = -1;
		while (param->game.map[a][++b])
		{
			if (param->game.map[a][b] == 'I')
			{
				display_image(param, "textures/brick_1.xpm", a, b);
				display_image(param, param->fire[p], a, b);
			}
			else if (param->game.map[a][b] == 'C')
			{
				display_image(param, "textures/brick_1.xpm", a, b);
				display_image(param, param->coin[k], a, b);
			}
		}
	}
	if (p++ == 3)
		p = 0;
	if (k++ == 7)
		k = 0;
}

int	animate(t_image_data *param)
{
	static int	n;

	if (n == 1000)
	{
		n = 0;
		display_animation(param, -1, -1);
	}
	n++;
	return (1);
}

void	render_image(t_game map)
{
	t_image_data	*i_data;

	i_data = malloc(sizeof(t_image_data));
	i_data->coin = init_coins();
	i_data->fire = init_fire();
	i_data->game = map;
	i_data->mlx = mlx_init();
	i_data->mlx_win = mlx_new_window(i_data->mlx, map.width * 50, map.height
			* 50, "so_long");
	display_map_in_window(i_data);
	mlx_hook(i_data->mlx_win, 2, 0, press_key, i_data);
	mlx_loop_hook(i_data->mlx, animate, i_data);
	mlx_key_hook(i_data->mlx_win, clear, i_data);
	mlx_hook(i_data->mlx_win, 17, 0, exit_win, i_data);
	mlx_loop(i_data->mlx);
}
