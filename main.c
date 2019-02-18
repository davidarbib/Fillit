/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:57:39 by pitriche          #+#    #+#             */
/*   Updated: 2019/02/18 17:39:54 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

/*
** display
** final display function, display in the right format
** -
** takes the string and the square's size
** returns nothing
*/

void	display(char *str)
{
	int i;
	int size;

	i = 0;
	size = slow_sqrt(ft_strlen(str));
	while (*str)
	{
		ft_putchar(*(str++));
		++i % size == 0 && i != 0 ? ft_putchar('\n') : 0;
	}
}

/*
** main
** final main, do fillit.
** -
** takes the main's arguments
** returns 0
*/

int		main(int ac, char **av)
{
	char	**tets;
	char	*map;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}
	if (!(tets = parse_tets(av[1])))
	{
		ft_putstr("error\n");
		return (0);
	}
	display(map = fillit(tets));
	free(map);
	ac = 0;
	while (tets[ac])
		free(tets[ac++]);
	free(tets);
	return (0);
}
