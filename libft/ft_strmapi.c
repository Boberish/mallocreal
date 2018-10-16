/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:21:12 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/07 22:23:34 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*s1;
	char	*new;
	char	*start;

	if (!s)
		return (NULL);
	s1 = (char*)s;
	new = (char*)malloc(sizeof(*new) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	start = new;
	while (*s1)
	{
		*new = f(new - start, *s1);
		new++;
		s1++;
	}
	*new = '\0';
	return (start);
}
