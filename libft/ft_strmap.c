/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:59:03 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/07 22:22:35 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char *s1;
	char *new;
	char *start;

	s1 = (char*)s;
	if (!s)
		return (NULL);
	new = (char*)malloc(sizeof(*new) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	start = new;
	while (*s1)
	{
		*new = f(*s1);
		s1++;
		new++;
	}
	*new = '\0';
	return (start);
}
