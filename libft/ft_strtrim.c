/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:29:07 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/07 22:44:04 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*new;
	int		len;
	char	*start;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len > 0)
		len--;
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s && len > 0)
	{
		len--;
		s++;
	}
	if (len)
		len++;
	new = (char*)malloc(sizeof(*new) * (len + 1));
	if (!new)
		return (NULL);
	start = new;
	while (len--)
		*(new++) = *(s++);
	*new = '\0';
	return (start);
}
