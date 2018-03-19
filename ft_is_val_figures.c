/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_val_figures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:52:06 by alukyane          #+#    #+#             */
/*   Updated: 2017/11/19 20:52:15 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_valid_sharp_count(char **figures, int i)
{
	int		j;
	int		k;
	int		sharp;

	sharp = 0;
	j = 0;
	k = i + 4;
	while (i < k)
	{
		while (figures[i][j] != '\0')
		{
			if (figures[i][j] == '#')
				sharp++;
			j++;
		}
		i++;
		j = 0;
	}
	if (sharp != 4)
		return (0);
	return (1);
}

int			ft_touch_sharp(char **figures, int i, int j, int sharp)
{
	if (sharp == 1 && ((figures[i][j + 1] == '#' || ((i + 1) % 4 != 0
		&& figures[i + 1][j] == '#')) || (figures[i][j - 1] == '#'
		&& figures[i + 1][j - 1] == '#' && figures[i + 1][j - 2] == '#'
		&& j > 1)))
		return (1);
	else
		return (0);
}

int			ft_check_figure(char **figures, int i, int sharp)
{
	int		j;

	j = 0;
	while (figures[i][j] != '\0')
	{
		if (figures[i][j] == '#')
		{
			if (!(figures[i][j + 1] == '#' || ((i + 1) % 4 != 0
				&& figures[i + 1][j] == '#') ||
				(j != 0 && figures[i][j - 1] == '#') ||
				(i != 0 && figures[i - 1][j] == '#')))
				return (-1);
			if ((sharp == 1) && ft_touch_sharp(figures, i, j, sharp) == 0)
				return (-1);
			sharp++;
		}
		j++;
	}
	return (sharp);
}

int			ft_is_val_tetr(char **figures, int i)
{
	int		k;
	int		sharp;

	sharp = 0;
	k = i + 4;
	if (ft_valid_sharp_count(figures, i) == 0)
		return (0);
	while (i < k && sharp < 4)
	{
		sharp = ft_check_figure(figures, i, sharp);
		if (sharp == -1)
			return (0);
		i++;
	}
	return (1);
}

int			ft_is_val_figures(char **figures)
{
	int		length_arr;
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (figures[i])
		i++;
	length_arr = i;
	i = 0;
	while (i < length_arr)
	{
		if (ft_is_val_tetr(figures, i) == 0)
			return (0);
		count++;
		i += 4;
	}
	return (count);
}
