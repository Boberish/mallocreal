/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 10:53:43 by jaylor            #+#    #+#             */
/*   Updated: 2016/11/28 14:20:58 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dest, const char *src)
{
	int index;

	index = 0;
	while ((dest[index] = src[index]) != '\0')
	{
		index++;
	}
	return (dest);
}
