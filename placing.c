/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 09:48:24 by darbib            #+#    #+#             */
/*   Updated: 2019/02/28 09:50:22 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** controls if is possible to place all blocks of a tetrimino
** return 1 for success, 0 else
*/

static int		allowed(t_fillit *state, char *tet, int *idx_tet, int *idx_sqr)
{
	int n_blocks;

	n_blocks = 0;
	while (tet[*idx_tet] && state->square[*idx_sqr] && n_blocks < 4)
	{
		if (tet[*idx_tet] != '.' && state->square[*idx_sqr] == '.')
		{
			if ((*idx_sqr + 1) / state->size != (*idx_sqr / state->size)
				&& (*idx_tet + 1) / 4 == (*idx_tet / 4)
				&& (tet[*idx_tet] != '.' && tet[*idx_tet + 1] != '.'))
				return (0);
			n_blocks++;
		}
		*idx_tet += 1;
		*idx_sqr = state->size * ((*idx_tet) / 4) + ((*idx_tet) % 4)
					+ state->drift;
	}
	if (n_blocks != 4)
		return (0);
	return (1);
}

/*
** try to realize a fusion between a drifted (or not) tetrimino and the square
** return 1 if success, 0 else
*/

unsigned int	place_tet(t_fillit *state, int drift, int i)
{
	char			*tet;
	int				idx_sqr;
	int				idx_tet;
	unsigned int	n_blocks;

	tet = state->tets[i];
	n_blocks = 0;
	idx_tet = 0;
	idx_sqr = state->size * (idx_tet / 4) + (idx_tet % 4) + drift;
	state->drift = drift;
	if (!allowed(state, tet, &idx_tet, &idx_sqr))
		return (0);
	while (idx_tet >= 0)
	{
		if (tet[idx_tet] != '.' && state->square[idx_sqr] == '.')
			state->square[idx_sqr] = 'A' + i;
		idx_tet--;
		idx_sqr = state->size * (idx_tet / 4) + (idx_tet % 4) + drift;
	}
	return (1);
}

static int		try2place(t_fillit *state, int i_tet, int n_placed, int drift)
{
	if (n_placed == state->nb_tets)
		return (1);
	if (i_tet == state->nb_tets)
		return (0);
	while (drift < state->size * state->size)
	{
		if (place_tet(state, drift, i_tet))
		{
			if (try2place(state, i_tet + 1, n_placed + 1, 0))
				return (1);
			remove_tet(state->square, i_tet);
		}
		drift++;
	}
	if (try2place(state, i_tet + 1, n_placed, 0))
		return (1);
	return (0);
}

char			*fillit(char **tets)
{
	char			*square;
	t_fillit		state;
	int				nb_tets;
	int				i;

	nb_tets = 0;
	while (tets[nb_tets])
		nb_tets++;
	state.nb_tets = nb_tets;
	state.size = slow_sqrt(nb_tets * 4);
	if (!(square = ft_strnew(state.size * state.size)))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < state.size * state.size)
		square[i++] = '.';
	state.drift = 0;
	state.tets = tets;
	state.square = square;
	while (!(try2place(&state, 0, 0, 0)))
		state.square = increase(state.square, ++(state.size));
	return (state.square);
}
