/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 10:32:56 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/12 10:42:55 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim_end(char *str)
{
	char	*start;
	char	*nstr;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str) - 1;
	while ((str[len] == ' ' || str[len] == '\t' || str[len] == '\n') && len > 0)
		len--;
	if (len)
		len++;
	nstr = (char*)malloc(sizeof(*nstr) * (len + 1));
	if (!nstr)
		return (NULL);
	start = nstr;
	while (len--)
		*(nstr++) = *(str++);
	*nstr = '\0';
	return (start);
}
