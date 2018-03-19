/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:09:32 by alukyane          #+#    #+#             */
/*   Updated: 2017/11/29 19:10:20 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef	struct	s_tetrimin
{
	char				**val;
	int					available;
	struct s_tetrimin	*next;
}				t_tetrim;
typedef struct	s_index
{
	int i;
	int j;
}				t_idx;
typedef struct	s_ijkeykq
{
	int		i;
	int		j;
	int		key;
	int		k;
	int		q;
	int		c;
	t_idx	idx;
}				t_op;
void			ft_putchar(char c);
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			ft_putstr(char const *str);
size_t			ft_strlen(const char *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_make_square(int count);
int				ft_caninsert(char **map, t_idx idx, t_tetrim *tetr, int size);
char			**ft_mapcpy(char **map, int size);
void			ft_print_map(char **map, int size);
int				ft_calc_size(char **map, int mapsize);
int				ft_isavailable(t_tetrim *tetrs);
int				ft_count_tetrs(t_tetrim *tetrs);
t_tetrim		*ft_lstcpy(t_tetrim *tetrims);
char			**ft_filling(t_tetrim *tetrs, char **map, int mapsize);
char			*ft_read_from_file(char *str);
char			*ft_strdup_read(char *src, int extra);
int				ft_is_valid_str(char *str);
int				ft_is_val_figures(char **figures);
char			*ft_str_chr_cpy(char *dest, const char *src, char c);
t_tetrim		*ft_make_arr_tetrs(char *filecontent);
void			ft_fill_one(char **map, t_idx idx, t_tetrim *tetr, int size);
char			**ft_zapusk(char **map, t_tetrim *tetrs);
t_tetrim		*ft_lstcpy(t_tetrim *tetrims);

#endif
