/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprypesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:50:53 by vprypesh          #+#    #+#             */
/*   Updated: 2017/11/25 13:50:54 by vprypesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		ft_tetr_sym(t_tetrim *tetrs)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tetrs->val[i][j] != '.')
			{
				c = tetrs->val[i][j];
				return (c);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

char		**ft_remove_prev(char **map, t_tetrim *tetrs, int mapsize)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = ft_tetr_sym(tetrs);
	while (i < mapsize)
	{
		while (j < mapsize)
		{
			if (map[i][j] == c)
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	tetrs->available = 1;
	return (map);
}

int			ft_perebor(char **map, t_tetrim *tetrs, int mapsize)
{
	t_idx idx;

	idx.j = 0;
	idx.i = 0;
	if (!tetrs)
		return (1);
	while (idx.i < mapsize)
	{
		while (idx.j < mapsize)
		{
			if (ft_caninsert(map, idx, tetrs, mapsize))
			{
				ft_fill_one(map, idx, tetrs, mapsize);
				if (ft_perebor(map, tetrs->next, mapsize))
					return (1);
				map = ft_remove_prev(map, tetrs, mapsize);
			}
			idx.j++;
		}
		idx.j = 0;
		idx.i++;
	}
	return (0);
}

char		**ft_zapusk(char **map, t_tetrim *tetrs)
{
	int			size;
	t_tetrim	*tmp_tetr;

	size = 2;
	tmp_tetr = ft_lstcpy(tetrs);
	while (!ft_perebor(map, tmp_tetr, size))
	{
		map = ft_make_square(ft_count_tetrs(tetrs));
		tmp_tetr = ft_lstcpy(tetrs);
		size++;
	}
	return (map);
}
