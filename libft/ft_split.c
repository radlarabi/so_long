/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:37:51 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/22 21:51:27 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/so_long.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 1;
	i = 0;
	while (str && str[i])
	{
		if (str[i] != c && j)
		{
			count++;
			j = 0;
		}
		if (str[i] == c)
			j = 1;
		i++;
	}
	return (count);
}

static int	count_set(const char *str, char set, int i)
{
	while (str[i] && str[i] == set)
		i++;
	return (i);
}

static int	count_non_set(const char *str, char set, int i)
{
	while (str[i] && str[i] != set)
		i++;
	return (i);
}

static int	free_str(char **ret, int d)
{
	int	i;

	i = 0;
	if (!ret[d])
	{
		while (ret[i])
		{
			free(ret[i]);
			i++;
		}
		free(ret);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *str, char set)
{
	int		j;
	int		i;
	int		len;
	char	**ret;
	int		start;

	j = 0;
	i = 0;
	len = count_words((char *)str, set);
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	while (str && str[i])
	{
		start = count_set(str, set, i);
		i = count_non_set(str, set, start);
		if (len > j)
		{
			ret[j] = ft_substr(str, start, i - start);
			if (!free_str(ret, j++))
				return (NULL);
		}
	}
	ret[j] = NULL;
	return (ret);
}
