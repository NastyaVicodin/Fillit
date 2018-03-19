/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_arr_tetrs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:58:40 by alukyane          #+#    #+#             */
/*   Updated: 2017/11/19 18:58:41 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_record_one(char **tetr, char **figures, int i, char c)
{
	int		k;
	int		n;

	n = 0;
	k = i + 4;
	while (i < k)
	{
		tetr[n] = (char *)malloc(sizeof(char) * 5);
		if (tetr[n] == 0)
			return (0);
		ft_str_chr_cpy(tetr[n], figures[i], c);
		n++;
		i++;
	}
	tetr[n] = NULL;
	return (tetr);
}

t_tetrim		*ft_record_tetrs(t_tetrim *arr_tetrs, char **fig, int count)
{
	int		i;
	int		k;
	char	c;

	c = 'A';
	k = 0;
	i = 0;
	while (i < count)
	{
		arr_tetrs[i].val = (char **)malloc(sizeof(char*) * 5);
		if (arr_tetrs[i].val == 0)
			return (0);
		arr_tetrs[i].val = ft_record_one(arr_tetrs[i].val, fig, k, c);
		arr_tetrs[i].available = 1;
		k += 4;
		c++;
		i++;
	}
	return (arr_tetrs);
}

t_tetrim		*ft_make_arr_tetrs(char *file_content)
{
	t_tetrim	*arr_tetrs;
	char		**figures;
	int			count;

	figures = ft_strsplit(file_content, '\n');
	count = ft_is_val_figures(figures);
	if (count == 0)
		return (0);
	arr_tetrs = (t_tetrim *)malloc(sizeof(t_tetrim) * count);
	if (arr_tetrs == 0)
		return (0);
	arr_tetrs = ft_record_tetrs(arr_tetrs, figures, count);
	return (arr_tetrs);
}
