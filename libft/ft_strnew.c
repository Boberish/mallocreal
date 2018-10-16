/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:02:21 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/28 13:59:19 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	char	*start;
	size_t	i;

	i = 0;
	s = (char*)malloc(sizeof(*s) * (size + 1));
	if (!s)
		return (NULL);
	start = s;
	while (i <= size)
	{
		*s = '\0';
		s++;
		i++;
	}
	return (start);
}
