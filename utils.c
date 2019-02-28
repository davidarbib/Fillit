/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:53:14 by darbib            #+#    #+#             */
/*   Updated: 2019/02/28 09:50:22 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int				slow_sqrt(int nb)
{
	int i;

	i = 0;
	while ((i * i) < nb)
		i++;
	return (i);
}

char			*increase(char *square, int size)
{
	char	*new_square;
	int		i;

	if (!(new_square = ft_strnew(size * size)))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size * size)
	{
		new_square[i] = '.';
		i++;
	}
	ft_strdel(&square);
	return (new_square);
}

void			remove_tet(char *square, int i)
{
	char	*p_square;

	p_square = square;
	while (*p_square)
	{
		if (*p_square == ('A' + i))
			*p_square = '.';
		p_square++;
	}
}
