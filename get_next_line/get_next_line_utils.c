/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:53:25 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/20 22:37:30 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/so_long.h"

int	ret_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i + 1);
}

int	end_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*a;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	a = (char *)malloc(i * sizeof(char) + 1);
	if (!a)
		return (0);
	i = -1;
	while (s1[++i])
		a[i] = s1[i];
	a[i] = '\0';
	return (a);
}
