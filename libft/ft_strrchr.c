/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:26:11 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/07 21:03:02 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*curr;
	int			flag;

	flag = 0;
	while (*s)
	{
		if (c == *s)
		{
			curr = s;
			flag = 1;
		}
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	if (flag == 0)
		return (NULL);
	return ((char*)curr);
}
