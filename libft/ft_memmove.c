/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:03:11 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/12 10:02:32 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char*)malloc(sizeof(unsigned char) * len + 1);
	if (temp)
	{
		ft_memcpy(temp, src, len);
		ft_memcpy(dst, temp, len);
	}
	return (dst);
}
