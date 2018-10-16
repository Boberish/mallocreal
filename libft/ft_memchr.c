/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:51:06 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/11 18:14:20 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*st;

	st = (unsigned char*)s;
	while (n--)
	{
		if (*st == (unsigned char)c)
			return ((void*)st);
		st++;
	}
	return (NULL);
}
