/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:50:11 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/07 21:09:34 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *st1;
	unsigned char *st2;

	st1 = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	while ((unsigned char)n)
	{
		if (*st1 == *st2)
		{
			st1++;
			st2++;
		}
		else
			return (*st1 - *st2);
		n--;
	}
	return (0);
}
