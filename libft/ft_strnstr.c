/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:38:21 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/12 09:54:42 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		index;
	size_t		x;
	size_t		y;

	y = 0;
	if (*little == '\0')
		return ((char*)big);
	while (big[y] != '\0' && len > 0)
	{
		index = 0;
		x = y;
		while (big[x] == little[index] && big[x] != '\0' && index < len)
		{
			index++;
			x++;
			if (little[index] == '\0')
				return ((char*)(big + y));
		}
		y++;
		len--;
	}
	return (NULL);
}
