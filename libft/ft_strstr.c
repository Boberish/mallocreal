/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:38:21 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/12 09:51:38 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int			index;
	const char	*s;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0' && *little != '\0')
	{
		if (*big == *little)
		{
			index = 0;
			s = big;
			while (*s == little[index] || little[index] == '\0')
			{
				if (little[index] == '\0')
				{
					s = s - index;
					return ((char*)big);
				}
				index++;
				s++;
			}
		}
		big++;
	}
	return (NULL);
}
