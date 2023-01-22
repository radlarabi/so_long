/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:31:59 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/21 20:34:08 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int check_map_1(t_game m)
{
    if (!if_exist(m.map, 'E') || !if_exist(m.map, '1') 
        || !if_exist(m.map, 'C') || !if_exist(m.map, 'P') 
            || !is_duplicate(m.map, 'P') || !is_duplicate(m.map, 'E'))
    {
        write(2, "Error one of the caracters do not exist or duplicate\n", 53);
        return 0;
    }
    if (!check_caracters(m.map))
    {
        write(2, "Error caracters of map\n", 23);
        return 0;
    }
    return 1;
}

int check_map_2(t_game m, int i, int j)
{
    while (m.map[++i])
    {
        if(((int)ft_strlen(m.map[i]) != m.width) || m.map[i][0] != '1' 
            || m.map[i][m.width - 1] != '1' )
        {
            write(2, "Error width of map\n", 19);
            return 0;
        }
        if (i == 0 || i == m.height - 1)
        {
            j = -1;
            while (m.map[i][++j])
            {
                if (m.map[i][j] != '1')
                {
                    write(2, "Error closed (Wall) of map\n", 27);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int check_map(t_game m)
{
    char **map1;
    char **map2;
    
    map1 = ft_split(m.origin_map, '\n');
    map2 = ft_split(m.origin_map, '\n');
    t_pos p = get_position(map1, 'P');
    if (!check_map_1(m) || !check_map_2(m, -1, -1))
        return 0;
    if (m.error == -1)
    {
        write(2, "Error height of map\n", 19);
        return 0;
    }
    // printf("%d\t%d\t%d\t%d\n", check_path(map1, p.i, p.j) , count_collec(m.map),p.i, p.j);
    if (check_path(map1, p.i, p.j) != count_collec(m.map))
    {
        write(2, "Error path of collection\n", 25);
        return 0;
    }
    if (!check_path_exit(map2, p.i, p.j))
    {
        write(2, "Error path of exit\n", 19);
        return 0;
    }
    free_2d_table(map1);
    free_2d_table(map2);
    return 1;
}

void display_map_in_window(t_image_data *i_data)
{
    int a;
    int b;

    a = 0;
    while (i_data->game.map[a])
    {
        b = 0;
        while(i_data->game.map[a][b])
        {
            display_image(i_data, "textures/brick_1.xpm",a , b);
            if (i_data->game.map[a][b] == '1')
                display_image(i_data, "textures/wall_5.xpm",a , b);
            else if (i_data->game.map[a][b] == 'E')
                display_image(i_data, "textures/close_door.xpm",a , b);
            else if (i_data->game.map[a][b] == 'C')
                display_image(i_data, "textures/coin1.xpm",a , b);
            else if (i_data->game.map[a][b] == 'P')
                display_image(i_data, "textures/player0.xpm",a , b);
            else if (i_data->game.map[a][b] == 'I')
                display_image(i_data, "textures/fire1.xpm",a , b);
            b++;
        }
        a++;
    }
}