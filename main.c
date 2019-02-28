/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:57:39 by pitriche          #+#    #+#             */
/*   Updated: 2019/02/28 09:47:56 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

#include <stdio.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void	pimp_display(char *str) // to remove
{
	int i;
	int size;

	i = 0;
	size = slow_sqrt(ft_strlen(str)); 
	while (*str)
	{
		*str == 'A' || *str == 'H' || *str == 'P' || *str == 'W' ? printf(RED "%c" RESET, *str) : 0;
		*str == 'B' || *str == 'I' || *str == 'Q' || *str == 'X' ? printf(GRN "%c" RESET, *str) : 0;
		*str == 'C' || *str == 'J' || *str == 'R' || *str == 'Y' ? printf(YEL "%c" RESET, *str) : 0;
		*str == 'D' || *str == 'K' || *str == 'S' || *str == 'Z' ? printf(BLU "%c" RESET, *str) : 0;
		*str == 'E' || *str == 'L' || *str == 'T' ? printf(MAG "%c" RESET, *str) : 0;
		*str == 'F' || *str == 'M' || *str == 'U' ? printf(CYN "%c" RESET, *str) : 0;
		*str == 'G' || *str == 'O' || *str == 'V' ? printf(WHT "%c" RESET, *str) : 0;
		fflush(0);
		*(str++) == '.' ? ft_putchar('.') : 0;
		++i % size == 0 && i != 0 ? ft_putchar('\n') : ft_putchar(' ');
	}
}
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
