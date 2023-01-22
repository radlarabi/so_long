/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:54:08 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/22 14:32:37 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
    int fd;
    t_game map;

    if (ac != 2)
        return 0;
    if(!check_args(av))
        return 0;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        write(2, "Error file\n", 11);
        return 0;
    }
    map = read_map(fd);
    if (!check_map(map))
        return 0;
    render_image(map);
    free_2d_table(map.map);
    free(map.origin_map);
   
    
    return (0);
}
