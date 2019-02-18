/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:43 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:29:44 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	x;

	x = -1;
	if (!dest || !src)
		return (NULL);
	while (src[++x] && (x < n))
		dest[x] = src[x];
	while (x < n)
		dest[x++] = '\0';
	return (dest);
}
