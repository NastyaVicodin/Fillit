/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:23:14 by alikhtor          #+#    #+#             */
/*   Updated: 2017/10/07 18:45:03 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_valid_symbols(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_valid_lines(char *str)
{
	int		i;
	int		line;
	int		symbol;

	symbol = 1;
	line = 1;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\n')
		{
			symbol++;
			i++;
		}
		if ((str[i] == '\n' && symbol == 5) || (str[i] == '\n' && symbol == 1 &&
			line % 5 == 0 && (i + 1) != (int)ft_strlen(str)))
			line++;
		else
			return (0);
		symbol = 1;
		i++;
	}
	return (1);
}

int		ft_is_valid_str(char *str)
{
	int	length;

	length = ft_strlen(str);
	if ((*str == 0) || (*str == '\n'))
		return (0);
	if (ft_is_valid_symbols(str) == 0 || ft_is_valid_lines(str) == 0
		|| length > 545 || (length + 1) % 21 != 0)
		return (0);
	return (1);
}
