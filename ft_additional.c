/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprypesh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:13:39 by vprypesh          #+#    #+#             */
/*   Updated: 2017/11/25 17:13:39 by vprypesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_isavailable(t_tetrim *tetrs)
{
	int			c;
	t_tetrim	*cur;

	cur = tetrs;
	c = 0;
	while (cur)
	{
		if (cur->available == 1)
		{
			c++;
		}
		cur = cur->next;
	}
	return (c);
}

char		**ft_mapcpy(char **map, int size)
{
	char	**new_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_map = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		new_map[i] = (char *)malloc(sizeof(char) * size + 1);
		while (j < size)
		{
			new_map[i][j] = map[i][j];
			j++;
		}
		new_map[i][j] = '\0';
		j = 0;
		i++;
	}
	return (new_map);
}

t_tetrim	*ft_lstcpy(t_tetrim *tetrims)
{
	t_tetrim	*new_tetrims;
	t_tetrim	*head;
	t_tetrim	*new_head;

	head = tetrims;
	new_tetrims = (t_tetrim *)malloc(sizeof(t_tetrim));
	new_tetrims->val = ft_mapcpy(tetrims->val, 4);
	new_tetrims->available = tetrims->available;
	new_head = new_tetrims;
	tetrims = tetrims->next;
	while (tetrims)
	{
		new_tetrims->next = (t_tetrim *)malloc(sizeof(t_tetrim));
		new_tetrims = new_tetrims->next;
		new_tetrims->available = tetrims->available;
		new_tetrims->val = ft_mapcpy(tetrims->val, 4);
		tetrims = tetrims->next;
	}
	tetrims = head;
	return (new_head);
}
