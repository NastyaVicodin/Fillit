/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:54:07 by alukyane          #+#    #+#             */
/*   Updated: 2017/09/25 19:54:09 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_str_chr_cpy(char *dest, const char *src, char c)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '#')
			dest[i] = c;
		else
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
