/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 19:28:10 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/11 19:34:40 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *s, char c)
{
	unsigned int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (count);
}
