/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:57:39 by pitriche          #+#    #+#             */
/*   Updated: 2019/02/28 09:48:06 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_fillit
{
	char	**tets;
	char	*square;
	int		size;
	int		nb_tets;
	int		drift;
}					t_fillit;

void				display(char *str);
char				**parse_tets(char *file);
char				*fillit(char **tets);
int					slow_sqrt(int nb);
char				*increase(char *square, int size);
void				remove_tet(char *square, int i);

#endif
