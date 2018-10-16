/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:38:52 by jaylor            #+#    #+#             */
/*   Updated: 2017/02/02 10:43:09 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char	*new;
	char	*beg;
	size_t	n;
	char	*tmp;

	tmp = (char*)s;
	n = len;
	if (!s)
		return (NULL);
	new = (char*)malloc(sizeof(*new) * (len + 1));
	if (!new)
		return (NULL);
	beg = new;
	while (n--)
		*(new++) = s[start++];
	*new = '\0';
	return (beg);
}
