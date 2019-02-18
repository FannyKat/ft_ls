/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:05:03 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:25:49 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_ishexa(int c)
{
	return ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}
