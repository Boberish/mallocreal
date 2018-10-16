/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:36:38 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/12 09:42:08 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned int index;

	index = 0;
	while (len > 0 && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
		len--;
	}
	while (len > 0 && dest[index] != '\0')
	{
		dest[index] = '\0';
		len--;
		index++;
	}
	return (dest);
}
