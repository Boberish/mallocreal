/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 13:28:45 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/11 18:19:11 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while ((*a && *b) && n)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
		n--;
	}
	if (n)
		return (*a - *b);
	return (0);
}
