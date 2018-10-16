/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 10:45:31 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/11 19:35:02 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mover(int *len, char *s1, char c)
{
	*len = 0;
	while (*s1 == c && *s1)
		s1++;
	while (*s1 != c && *s1)
	{
		*len = *len + 1;
		s1++;
	}
	return (s1);
}

char		**ft_strsplit(const char *s, char c)
{
	char			*s1;
	unsigned int	count;
	char			**keat;
	int				len;
	unsigned int	i;

	s1 = (char*)s;
	count = ft_count_words(s1, c);
	if (!(keat = (char**)malloc(sizeof(*keat) * (count + 1))))
		return (NULL);
	while (count--)
	{
		s1 = mover(&len, s1, c);
		*keat = ft_strnew(len);
		i = len;
		while (len)
		{
			**keat = *(s1 - len--);
			(*keat)++;
		}
		*keat = *keat - i;
		keat++;
	}
	*keat = 0;
	return (keat - ft_count_words((char*)s, c));
}
