/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:27:29 by ytouab            #+#    #+#             */
/*   Updated: 2022/11/10 22:28:02 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	ft_replace_texture(t_all *all, char *direction, int a)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strncmp(all->textures[a], direction, 3))
		ft_error(all, 10);
	tmp = ft_substr(all->textures[a], 3, ft_strlen(all->textures[a]));
	if (!tmp)
		return ;
	free(all->textures[a]);
	all->textures[a] = ft_strdup(tmp);
	free(tmp);
}

void	ft_texture(t_all *all)
{
	size_t	i;
	int		rd;

	i = 0;
	rd = 0;
	ft_replace_texture(all, "NO ", 0);
	ft_replace_texture(all, "SO ", 1);
	ft_replace_texture(all, "WE ", 2);
	ft_replace_texture(all, "EA ", 3);
	while (i < 4)
	{
		rd = open(all->textures[i], O_RDONLY);
		if (rd < 0)
			ft_error(all, 10);
		close(rd);
		i++;
	}
}
