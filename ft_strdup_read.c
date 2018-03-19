/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:45:44 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/27 17:45:45 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strdup_read(char *src, int extra)
{
	char			*res;
	unsigned int	len;

	res = src;
	len = 1;
	while (*res)
	{
		res++;
		len++;
	}
	res = (char*)malloc(sizeof(char) * (len + extra));
	return (ft_strcpy(res, src));
}
