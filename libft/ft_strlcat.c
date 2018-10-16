/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:24:27 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/11 18:11:46 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*temp;
	int		len;
	char	*start;
	int		n;

	start = (char*)src;
	temp = dst;
	n = size;
	while (*temp && n--)
		temp++;
	len = temp - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(src));
	while (*src)
	{
		if (n-- - 1 > 0)
		{
			*temp = *src;
			temp++;
		}
		src++;
	}
	*temp = '\0';
	return (len + (src - start));
}
