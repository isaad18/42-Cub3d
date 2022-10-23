/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:53:04 by ytouab            #+#    #+#             */
/*   Updated: 2022/10/23 13:49:52 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	if (!str)
		return (0);
	while (str[l])
		l++;
	return (l);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return ;
	l = ft_strlen(s);
	while (i < l)
		write(fd, &s[i++], 1);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (i < (int)ft_strlen(str) && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

size_t	ft_delimiter(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

size_t	ft_wordcount(char *str)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_delimiter(str[i]))
			i++;
		if (str[i] && !ft_delimiter(str[i]))
			nb++;
		while (str[i] && !ft_delimiter(str[i]))
			i++;
	}
	return (nb);
}

char	**ft_split(char *str, t_all *all)
{
	char	**ret;
	size_t	wordc;
	size_t	i;
	size_t	x;

	wordc = ft_wordcount(str);
	ret = (char **)malloc((wordc + 1) * sizeof(char *));
	if (!ret)
		ft_error(all, 4);
	i = 0;
	while (i < wordc)
	{
		while (*str && ft_delimiter(*str))
			str++;
		x = 0;
		while (str[x] && !ft_delimiter(str[x]))
			x++;
		ret[i] = (char *)malloc(x + 1);
		x = 0;
		while (*str && !ft_delimiter(*str))
			ret[i][x++] = *str++;
		ret[i++][x] = 0;
	}
	ret[i] = NULL;
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	a[4];

	a[0] = 0;
	a[1] = 0;
	if (!s1 || !s2)
		return (0);
	a[2] = ft_strlen(s1);
	a[3] = ft_strlen(s2);
	ret = (char *)malloc((a[2] + a[3] + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (a[0] < a[2])
	{
		ret[a[0]] = s1[a[0]];
		a[0]++;
	}
	while (a[1] < a[3])
		ret[a[0]++] = s2[a[1]++];
	ret[a[0]] = 0;
	free(s1);
	return (ret);
}

size_t	ft_arr_len(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

void	ft_arr_print(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		ft_putstr_fd(arr[i++], 1);
		ft_putstr_fd("\n", 1);
	}
}

char	**ft_arr_dup(char **arr, size_t start, size_t size)
{
	size_t	i;
	size_t	j;
	char	**ret;

	if (!size)
		return (NULL);
	i = start;
	j = 0;
	ret = (char **)malloc((size + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while ((i < (start + size)) && arr[i])
		ret[j++] = ft_strdup(arr[i++]);
	ret[j] = NULL;
	return (ret);
}

