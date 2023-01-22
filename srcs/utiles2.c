/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:31:02 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/21 20:40:35 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(char **av)
{
    int		i;

    i = 0;
	while (av[1][i])
		i++;
    if (av[1][--i] != 'r' || av[1][--i] != 'e' || av[1][--i] != 'b'
    || av[1][--i] != '.')
    {
        write(2, "Error Args\n", 11);
        return (0); 
    }
    return 1;
}

t_game read_map(int fd)
{
    char *ret;
    char *temp;
    t_game m;

    m.height = 0;
    ret = NULL;
    while(1)
    {
        temp = get_next_line(fd);
        if (temp == NULL)
            break;
        if (!ft_strncmp(temp, "\n", 2))
            m.error = -1;
        ret = ft_strjoin(ret, temp);
        m.height++;
        free(temp);
    }
    m.origin_map = ret;
    m.map = ft_split(ret, '\n');
    m.timer1 = 0;
    m.width = ft_strlen(m.map[0]);
    m.coll = count_collec(m.map);
    return m;
}

int check_caracters(char **map)
{
    int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' 
                || map[i][j] == 'C' || map[i][j] == '0' 
                    || map[i][j] == '1' || map[i][j] == 'I')
				j++;
			else
                return 0;
		}
		i++;
	}
    return 1;
}

int check_path(char **map, int a, int b)
{
    int count;

    count = 0;
    if (map[a][b] == '1' || map[a][b] == 'E' || map[a][b] == 'x' || map[a][b] == 'I')
        return count;
    if (map[a][b] == '0' || map[a][b] == 'P' || map[a][b] == 'C')
    {
        if (map[a][b] == 'C')
            count++;
        map[a][b] = 'x';
        count += check_path(map, a - 1, b);
        count += check_path(map, a, b + 1);
        count += check_path(map, a + 1, b);
        count += check_path(map, a , b - 1);
    }
    return count;
}

int check_path_exit(char **map, int a, int b)
{
    int count;

    count = 0;
    if (map[a][b] == '1' || map[a][b] == 'x' || map[a][b] == 'I')
        return count;
    if (map[a][b] == '0' || map[a][b] == 'P' || map[a][b] == 'C'  || map[a][b] == 'E')
    {
        if (map[a][b] == 'E')
            count++;
        map[a][b] = 'x';
        count += check_path_exit(map, a - 1, b);
        count += check_path_exit(map, a, b + 1);
        count += check_path_exit(map, a + 1, b);
        count += check_path_exit(map, a , b - 1);
    }
    return count;
}