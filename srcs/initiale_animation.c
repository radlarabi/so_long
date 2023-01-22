/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiale_animation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:45:02 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/22 14:09:33 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **init_coins()
{
    char **coin;

    coin = malloc(sizeof(char *) * 9);
    coin[0] = ft_strdup("textures/coin1.xpm");
    coin[1] = ft_strdup("textures/coin2.xpm");
    coin[2] = ft_strdup("textures/coin3.xpm");
    coin[3] = ft_strdup("textures/coin4.xpm");
    coin[4] = ft_strdup("textures/coin5.xpm");
    coin[5] = ft_strdup("textures/coin9.xpm");
    coin[6] = ft_strdup("textures/coin8.xpm");
    coin[7] = ft_strdup("textures/coin7.xpm");
    return coin;
}

char **init_fire()
{
    char **fire;

    fire = malloc(sizeof(char *) * 5);
    fire[0] = ft_strdup("textures/fire1.xpm");
    fire[1] = ft_strdup("textures/fire2.xpm");
    fire[2] = ft_strdup("textures/fire3.xpm");
    fire[3] = ft_strdup("textures/fire4.xpm");
    return fire;
}
