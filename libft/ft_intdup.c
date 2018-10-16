/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <jaylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:18:47 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/30 10:52:01 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		*ft_intdup(int *array)
{
	int	*new;
	int	i;

	i = 0;
	while (array[i] >= 0)
		i++;
	new = malloc(sizeof(int) * (i + 1));
	ft_intset(new, -1, i + 1);
	i = 0;
	while (array[i] != -1)
	{
		new[i] = array[i];
		i++;
	}
	return (new);
}
