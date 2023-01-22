/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:09:01 by rlarabi           #+#    #+#             */
/*   Updated: 2023/01/21 20:35:31 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (c1[i] != '\0' || c2[i] != '\0'))
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}

int strlen_2d(char **a)
{
	int i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
int if_exist(char **a, char c)
{
	int i;
	int j;

	i = 0;	
	while (a[i])
	{
		j = 0;
		while(a[i][j])
		{
			if(a[i][j] == c)
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

int	is_duplicate(char **a, char c)
{
	int	i;
	int	j;
	int count;

	count  = 0;
	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	else
		return (1);
}

t_pos get_position(char **map, char m)
{
	t_pos p;
	int i;
    int j;

	i  = 0;
	j = 0;
	p.i = 0;
	p.j = 0;
    while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == m)
			{
				p.i = i;
				p.j = j;
				return p;
			}
			j++;
		}
		i++;
	}
	return p;
}

int count_collec(char **a)
{
    int	i;
	int	j;
	int count;

	count  = 0;
	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
    return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a_len;
	int		b_len;
	int		i;
	char	*ret;

	if (!s1)
		return ft_strdup(s2);
	a_len = ft_strlen((char *)s1);
	b_len = ft_strlen((char *)s2);
	i = -1;
	ret = (char *)malloc(sizeof(char) * (a_len + b_len + 1));
	if (!ret)
		return (0);
	while (s1[++i])
		ret[i] = s1[i];
	i = -1;
	while (s2[++i])
		ret[a_len + i] = s2[i];
	ret[a_len + i] = '\0';
	return (ret);
}

/********************************* split ********************************/
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ret = (char *)malloc(len * sizeof(char) + 1);
	if (!ret)
		return (NULL);
	while (s[i] && i < len)
	{
		ret[i] = s[start++];
		i++;
	}
	ret[i] = '\0';
	return (ret);
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
/********************************* split ********************************/