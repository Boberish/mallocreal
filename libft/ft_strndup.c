/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:14:00 by jaylor            #+#    #+#             */
/*   Updated: 2017/01/27 14:05:05 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	char	*temp;

	if (!(str = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	temp = str;
	while (n > 0)
	{
		*temp = *s1;
		temp++;
		s1++;
		n--;
	}
	*temp = '\0';
	return (str);
}
