/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/02/04 15:59:47 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *strc)
{
	char		*str;
	unsigned	r;
	int			s;

	str = (char *)strc;
	while (*str == '\f' || *str == '\n' || *str == '\r' || *str == '\v' ||
		*str == '\t' || *str == ' ')
		str++;
	r = 0;
	s = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
		r = r * 10 + *str - '0';
		str++;
	}
	return (r * s);
}
