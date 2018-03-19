/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprypesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:29:26 by vprypesh          #+#    #+#             */
/*   Updated: 2017/11/25 16:29:28 by vprypesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char	**ft_create_map(int count)
{
	char	**map;
	int		i;
	int		j;

	j = 0;
	i = 0;
	map = (char **)malloc(sizeof(char *) * count);
	while (i < count)
	{
		map[i] = (char *)malloc(sizeof(char) * count + 1);
		while (j < count)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
		j = 0;
	}
	return (map);
}

char			**ft_make_square(int count)
{
	char	**map;

	map = ft_create_map(count * 4);
	return (map);
}

void			ft_hello_world(char **map, t_op *top, t_tetrim *tetr, int size)
{
	while (top->i < 4)
	{
		while (top->j < 4)
		{
			if (tetr->val[top->i][top->j] != '.')
				if (top->key == -1)
				{
					top->key = 42;
					top->k = top->i;
					top->q = top->j;
				}
			if (tetr->val[top->i][top->j] != '.' && (top->idx.i + top->i -
			top->k) < size && (top->idx.j + top->j - top->q) < size && map
			[top->idx.i + top->i - top->k][top->idx.j + top->j - top->q] == '.')
			{
				if (map[top->idx.i + top->i - top->i]
					[top->idx.j + top->j - top->j] != '.')
					return ;
				top->c++;
			}
			top->j++;
		}
		top->j = 0;
		top->i++;
	}
}

int				ft_caninsert(char **map, t_idx idx, t_tetrim *tetr, int size)
{
	t_op	*top;

	top = (t_op *)malloc(sizeof(t_op));
	top->key = -1;
	top->k = 0;
	top->q = 0;
	top->i = 0;
	top->j = 0;
	top->c = 0;
	top->idx = idx;
	ft_hello_world(map, top, tetr, size);
	if (top->c == 4)
		return (1);
	return (0);
}
