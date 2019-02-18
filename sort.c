/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 03:21:18 by maboye            #+#    #+#             */
/*   Updated: 2019/02/18 14:42:18 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			sort_av(char **av)
{
	int		size;
	int		x;
	int		y;

	size = -1;
	while (av[++size])
		;
	y = 0;
	while (++y < size)
	{
		x = 0;
		while (++x < size - 1)
			if (ft_strcmp(av[x + 1], av[x]) < 0)
				ft_swap((void**)&av[x + 1], (void**)&av[x]);
	}
}
