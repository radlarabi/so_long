/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:02:11 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/22 14:23:42 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 100000

typedef struct s_pos
{
	int		i;
	int		j;
}			t_pos;

typedef struct s_game
{
	int		height;
	int		width;
	int		coll;
	int		error;
	char	**map;
	int		emptie;
	int		timer1;
	int		timer2;
	char	*origin_map;
}			t_game;

typedef struct s_image_data
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	**coin;
	char	**fire;
	t_game	game;
}			t_image_data;

typedef struct s_key_events
{
	t_pos	p1;
	t_pos	p2;
}			t_key_events;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
/*    get next line utiles */
char		*get_next_line(int fd);
int			ret_line(char *str);
int			end_line(char *str);
size_t		ft_strlen(char const *str);
char		*ft_strdup(char *s1);
int			strlen_2d(char **a);
int			if_exist(char **a, char c);
int			is_duplicate(char **a, char c);
t_pos		get_position(char **map, char m);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *str, char set);
int			count_collec(char **a);
void		display_image(t_image_data *param, char *img, int a, int b);
int			moves(t_image_data *param, t_key_events events, int *count,
				int *steps);
void		swap_elm(char *a, char *b);
void		swap_images(t_image_data *param, t_pos p1, t_pos p2);
char		*ft_itoa(int n);
int			move_left(t_image_data *param, t_key_events events, int *count,
				int *steps);
int			move_right(t_image_data *param, t_key_events events, int *count,
				int *steps);
int			move_up(t_image_data *param, t_key_events events, int *count,
				int *steps);
int			move_down(t_image_data *param, t_key_events events, int *count,
				int *steps);
char		**init_fire();
char		**init_coins();
char		**init_player();
int			check_args(char **av);
t_game		read_map(int fd);
int			check_caracters(char **map);
int			check_path(char **map, int a, int b);
int			check_path_exit(char **map, int a, int b);
int			check_map_1(t_game m);
int			check_map_2(t_game m, int i, int j);
int			check_map(t_game m);
void		display_map_in_window(t_image_data *i_data);
void		render_image(t_game map);
int			animate(t_image_data *param);
void		display_animation(t_image_data *param);
int			press_key(int key, t_image_data *param);
void		swap_images(t_image_data *param, t_pos p1, t_pos p2);
int			clear(int key, t_image_data *param);
int			exit_win(t_image_data *param);
void		swap_elm(char *a, char *b);
void		free_2d_table(char **t);
#endif