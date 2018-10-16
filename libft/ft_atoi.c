/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 09:04:12 by jaylor            #+#    #+#             */
/*   Updated: 2017/11/29 19:19:41 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t		ft_atoi(const char *str)
{
	uintmax_t	num;
	int			index;

	index = 0;
	while (str[index] == ' ')
		index++;
	num = 0;
	while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9')
	{
		num = num * 10 + str[index] - '0';
		index++;
	}
	return (num);
}
