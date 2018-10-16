/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:12:55 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/10 23:18:43 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;
	unsigned char	*start;

	s = (void*)malloc(size);
	if (!s)
		return (NULL);
	start = s;
	while (size)
	{
		*s = '\0';
		size--;
		s++;
	}
	return ((void*)start);
}
