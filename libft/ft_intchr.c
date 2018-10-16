/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:26:25 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 10:52:37 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intchr(int *array, int match, int len)
{
	int	i;

	i = 0;
	while (len-- && *array != -1)
	{
		if (array[i] == match)
			return (1);
		i++;
	}
	return (0);
}
