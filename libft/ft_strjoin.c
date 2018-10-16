/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:08:48 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/28 14:37:26 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	len;
	char			*new;
	int				nl;
	int				nl2;

	nl2 = ft_strlen(s1);
	nl = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	s2 = s2 - (nl);
	s1 = s1 - (nl2);
	new = new - len;
	free(s1);
	return (new);
}
