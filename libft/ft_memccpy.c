/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:14:21 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/11 18:35:49 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	nc;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	nc = (unsigned char)c;
	while (n)
	{
		*d = *s;
		if (*d == nc)
			return (d + 1);
		d++;
		s++;
		n--;
	}
	return (0);
}
