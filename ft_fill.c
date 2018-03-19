/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprypesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:45:13 by vprypesh          #+#    #+#             */
/*   Updated: 2017/11/25 16:45:14 by vprypesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill(char **map, t_op top, t_tetrim *tetr, int size)
{
	while (top.i < 4)
	{
		while (top.j < 4)
		{
			if (tetr->val[top.i][top.j] != '.')
				if (top.key == -1)
				{
					top.key = 42;
					top.k = top.i;
					top.q = top.j;
				}
			if (tetr->val[top.i][top.j] != '.' && (top.idx.i + top.i - top.k)
			< size && (top.idx.j + top.j - top.q) < size
			&& map[top.idx.i + top.i - top.k][top.idx.j + top.j - top.q] == '.')
			{
				map[top.idx.i + top.i - top.k][top.idx.j + top.j - top.q] =
				tetr->val[top.i][top.j];
			}
			top.j++;
		}
		top.j = 0;
		top.i++;
	}
}

void	ft_fill_one(char **map, t_idx idx, t_tetrim *tetr, int size)
{
	t_op top;

	top.key = -1;
	top.k = 0;
	top.q = 0;
	top.i = 0;
	top.j = 0;
	top.idx = idx;
	ft_fill(map, top, tetr, size);
	tetr->available = 0;
}

void	ft_print_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

int		ft_calc_size(char **map, int mapsize)
{
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = 0;
	while (i < mapsize)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '.')
			{
				if (i > max)
					max = i;
				if (j > max)
					max = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (max + 1);
}

int		ft_count_tetrs(t_tetrim *tetrs)
{
	int i;

	i = 0;
	while (tetrs)
	{
		i++;
		tetrs = tetrs->next;
	}
	return (i);
}
