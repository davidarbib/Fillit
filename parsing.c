/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:01:07 by pitriche          #+#    #+#             */
/*   Updated: 2019/02/18 17:49:49 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
** reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
** REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
** REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
** -
** REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
** REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
*/

static int	reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee(char *reeee)
{
	int reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee;

	reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee = 0;
	while (*(reeee++))
	{
		if (*(reeee - 1) != '.' && *(reeee - 1) != '#')
			return (0);
		if (*(reeee - 1) == '#')
			reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee = 1;
	}
	if (!reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee)
		return (0);
	return (1);
}

/*
** is_dis_gud
** why would you make a beautiful algorythm to check the parts are all touching
** when you can fit 19 strcmp in a single function ?
** -
** takes a string containing a tetrimino (or not ?)
** returns 0 or 1 depending on it's mood
*/

static int	is_dis_gud(char *str)
{
	if (!ft_strcmp(str, "####............")
	|| !ft_strcmp(str, "#...#...#...#...")
	|| !ft_strcmp(str, "##..##..........")
	|| !ft_strcmp(str, ".#..###.........")
	|| !ft_strcmp(str, "#...##..#.......")
	|| !ft_strcmp(str, "###..#..........")
	|| !ft_strcmp(str, ".#..##...#......")
	|| !ft_strcmp(str, ".##.##..........")
	|| !ft_strcmp(str, "#...##...#......")
	|| !ft_strcmp(str, "##...##.........")
	|| !ft_strcmp(str, ".#..##..#.......")
	|| !ft_strcmp(str, "#...#...##......")
	|| !ft_strcmp(str, "###.#...........")
	|| !ft_strcmp(str, "##...#...#......")
	|| !ft_strcmp(str, "..#.###.........")
	|| !ft_strcmp(str, ".#...#..##......")
	|| !ft_strcmp(str, "#...###.........")
	|| !ft_strcmp(str, "##..#...#.......")
	|| !ft_strcmp(str, "###...#........."))
		return (1);
	return (0);
}

/*
** get_tet
** gather one tetrimino from an fd, and put it on a freshly allocated string
** -
** takes a file descriptor, and an int to tell if it's the last
** returns a fresh string containing the tetrimino, 0 if malloc fails or the
** tetrimino have the wrong shape or wrong characters
*/

static char	*get_tet(int fd, int *last)
{
	char	line[17];
	int		i;
	int		ret;

	i = 0;
	while (i < 16)
	{
		if ((read(fd, line + i, 4)) != 4)
			return (0);
		i += 4;
		if (read(fd, line + i, 1) != 1)
			return (0);
		if (line[i] != '\n')
			return (0);
	}
	if ((ret = read(fd, line + 16, 1)) < 0 || (ret && line[16] != '\n'))
		return (0);
	else if (!ret)
		*last = 1;
	line[16] = 0;
	return (ft_strdup(line));
}

/*
** parse_tet
** raise the tetrimino in the top left corner of it's 4*4 square, and check if
** it's a valid one
** -
** takes a string containing an unparsed tetrimino
** returns the string containing the now parsed tetrimino, or 0 if 0 is send or
** the tetrimino isn't valid
*/

static char	*parse_tet(char *str)
{
	if (!str)
		return (0);
	if (!reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee(str))
	{
		free(str);
		return (0);
	}
	while (str[0] != '#' && str[1] != '#' && str[2] != '#' && str[3] != '#')
	{
		ft_memmove(str, str + 4, 12);
		ft_strcpy(str + 12, "....");
	}
	while (str[0] != '#' && str[4] != '#' && str[8] != '#' && str[12] != '#')
	{
		ft_memmove(str, str + 1, 15);
		str[15] = '.';
	}
	if (!is_dis_gud(str))
	{
		free(str);
		return (0);
	}
	return (str);
}

/*
** parse_tets
** open a file, then stores the tetriminos from the file in an allocated array
** of strings, while keeping an eye on potential errors. The tetriminos are
** placed at the top left in their 4*4 square, represented by a 16 char string
** -
** takes a string describing the file to take tetriminos from
** returns an array of strings, null terminated, containing processed
** tetriminos. Returns 0 in case of error
*/

char		**parse_tets(char *file)
{
	int		fd;
	int		i;
	int		last;
	char	**tets;

	i = 0;
	last = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	if (!(tets = (char **)malloc(27 * sizeof(char *))))
		return (0);
	while (!last)
	{
		if (!(tets[i++] = parse_tet(get_tet(fd, &last))) || i > 26)
		{
			if (tets[i - 1] && i > 26)
				free(tets[i - 1]);
			while (--i)
				free(tets[i - 1]);
			free(tets);
			return (0);
		}
	}
	tets[i] = 0;
	return (tets);
}
